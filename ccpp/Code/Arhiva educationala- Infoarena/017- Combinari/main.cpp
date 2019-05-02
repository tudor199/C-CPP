#include <iostream>
#include <fstream>

#define nMax 20

using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

int n, k;
int st[nMax];

void print(){
    for(int i = 1; i <= k; i++){
        fout<<st[i]<<" ";
    }
    fout<<"\n";
    return;
}

void comb(int c){
    if(c == k + 1){
        print();
        return;
    }
    for(int i = st[c - 1] + 1; i <= n; i++){
        st[c] = i;
        comb(c + 1);
    }
    return;
}

int main(){
	fin>>n>>k;
	comb(1);
	return 0;
}
