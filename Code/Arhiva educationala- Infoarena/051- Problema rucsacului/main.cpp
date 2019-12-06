#include <iostream>
#include <fstream>

#define nMax 5003
#define wMax 10003

#define MAX(a, b) (a > b ? a : b)

#define pl (i + 1) % 2
#define cl i % 2

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

int v[2][wMax];
int wei[nMax], prc[nMax];
int n, weight;

int main(){
    int v[2][wMax] = {};
    int wei[nMax], prc[nMax];
    int n, weight;
	fin>>n>>weight;
	for(int i = 1; i <= n; i++){
        fin>>wei[i]>>prc[i];
	}
	for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= weight; j++){
            if(wei[i] <= j){
                v[cl][j] = MAX(v[pl][j], v[pl][j - wei[i]] + prc[i]);
            }
            else{
                v[cl][j] = v[pl][j];
            }
        }
	}
	fout<<v[n % 2][weight];
	return 0;
}
