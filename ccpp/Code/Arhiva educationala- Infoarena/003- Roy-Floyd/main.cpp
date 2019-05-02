#include <iostream>
#include <fstream>

#define nMax 103
#define INF 1000000

using namespace std;

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

int main(){
    int n;
    int v[nMax][nMax];
	fin>>n;
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin>>v[i][j];
            if(!v[i][j]){
                v[i][j] = INF;
            }
        }
	}
	for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                if(v[i][j] > v[i][k] + v[k][j]){
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
	}
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fout<<(v[i][j] == INF ? 0 : v[i][j])<<" ";
        }
        fout<<"\n";
    }
	return 0;
}
