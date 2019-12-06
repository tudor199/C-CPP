#include <iostream>
#include <cstring>
#include <fstream>

#define MOD 666013

using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");

int mult(int a[2][2], int b[2][2]){
    int c[2][2] = {};
    for(int i = 0; i < 2 ; i ++){
        for(int j = 0; j < 2; j ++){
            for(int k = 0; k < 2; k ++){
                c[i][j] = (1ll * c[i][j] +  1ll * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    memcpy(a, c, sizeof(c));
}

int fib(int n){
    if(n == 0){
        return 0;
    }
    int a[2][2] = {0, 1, 1, 1}, z[2][2] = {0, 1, 1, 1};
    while(n){
       if(n & 1){
            mult(a, z);
            -- n;
       }
       else{
            mult(z, z);
            n /= 2;
       }
    }
    return a[0][0];
}

int main(){
    int n;
    fin>>n;
    fout<<fib(n);
	return 0;
}
