#include <iostream>
#include <fstream>

#define nMax 1000003

using namespace std;

ifstream fin("elmaj.in");
ofstream fout("elmaj.out");

int v[nMax];

pair < int, int > majoritar(int n){
    int cmaj, k = 0, counter = 0;
    if(n == 0){
        return make_pair(-1, 0);
    }
    for(int i = 1; i <= n; i++){
        if(k == 0){
            cmaj = v[i];
            k++;
        }
        else{
            if(v[i] == cmaj){
                k++;
            }
            else{
                k--;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(v[i] == cmaj){
            counter++;
        }
    }
    if(counter <= n / 2){
        return make_pair(-1, 0);
    }
    return make_pair(cmaj, counter);
}

int main(){
    int n;
	fin>>n;
	for(int i = 1; i <= n; i++){
        fin>>v[i];
	}
	pair < int, int > rez = majoritar(n);
	if(rez.first == -1){
        fout<<rez.first<<"\n";
	}
	else{
        fout<<rez.first<<" "<<rez.second<<"\n";
	}
	return 0;
}
