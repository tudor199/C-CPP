#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

long long invmod(long long a1, const long long MOD){
    long long a0 = MOD, b0 = MOD, b1 = 1, man, q;
    while(a1 > 1){
        q = a0 / a1;
        man = a1;
        a1 = a0 - q * a1;
        if(a1 < 0){
            a1 = MOD - ((-a1) % MOD);
        }
        a0 = man;
        man = b1;
        b1 = b0 - q * b1;
        if(b1 < 0){
            b1 = MOD - ((-b1) % MOD);
        }
        b0 = man;
    }
    if(a1 == 1){
        return b1;
    }
    return -1;
}

int main(){
    int a, m;
	fin>>a>>m;
	fout<<invmod(a, m);
	return 0;
}
