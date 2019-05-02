#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#define nMax 1000003

using namespace std;

ifstream fin("pinex.in");
ofstream fout("pinex.out");

vector < bool > viz(nMax, false);
vector < int > prim;

void erastothenes(){
    int stop = 1000000;
    for(int i = 3; i <= sqrt(stop); i += 2){
        if(!viz[i]){
            for(int j = 2; i * j <= stop; j++){
                viz[i * j] = true;
            }
        }
    }
    prim.push_back(2);
    for(int i = 3; i <= stop; i += 2){
        if(!viz[i]){
            prim.push_back(i);
        }
    }
}

int main(){
    int nrteste;
    long long a, b, numitor, rez;
    vector < int > divb;
    erastothenes();
    fin>>nrteste;
    while(nrteste--){
        rez = 0;
        fin>>a>>b;
        divb.resize(0);
        for(auto x : prim){
            if(b % x == 0){
                divb.push_back(x);
                while(b % x == 0){
                    b /= x;
                }
            }
        }
        if(b != 1){
            divb.push_back(b);
        }
        for(int idx = 1, sig, n = divb.size(); idx < (1 << n); idx++){
            sig = -1;
            numitor = 1;
            for(int i = 0; i < n; i++){
                if(idx & (1 << i)){
                    numitor *= divb[i];
                    sig *= -1;
                }
            }
            if(numitor != 1){
                rez += sig * (a / numitor);
            }
        }
        fout<<a - rez<<"\n";
    }
	return 0;
}
