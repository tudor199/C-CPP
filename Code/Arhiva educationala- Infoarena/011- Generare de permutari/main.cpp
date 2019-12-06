#include <iostream>
#include <fstream>

#define nMax 10

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

int n;
int st[nMax];
bool viz[nMax];

void print(){
    for(int i = 1; i <= n; i++){
        fout<<st[i]<<" ";
    }
    fout<<"\n";
    return;
}

void bk(int k){
    if(k == n){
        print();
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            st[k + 1] = i;
            viz[i] = true;
            bk(k + 1);
            viz[i] = false;
        }
    }
    return;
}

int main()
{
    fin>>n;
    bk(0);
    return 0;
}
