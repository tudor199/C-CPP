#include <iostream>
#include <fstream>

#define MOD 1999999973

using namespace std;

ifstream fin("lgput.in");
ofstream fout("lgput.out");

unsigned long long lgpow(int exp, int pow){
    if(pow == 1){
        return exp;
    }
    unsigned long long n = lgpow(exp, pow/2);
    return (((n * n) % MOD) * (pow & 1 ? exp : 1)) % MOD;
}

int main(){
	int n, put;
	fin>>n>>put;
	fout<<lgpow(n, put);
	return 0;
}
