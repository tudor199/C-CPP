#include <iostream>
#include <iomanip>
#include <fstream>

#define ABS(a) ((a) < 0 ? -(a) : (a))
#define SWAP(a, b) ((aux) = (a), (a) = (b), (b) = (aux))

#define nMax 303
#define EPS 0.0000001

using namespace std;

ifstream fin("gauss.in");
ofstream fout("gauss.out");


int main(){
    int n, m;
    double a[nMax][nMax];
    double q, aux, v[nMax], rez[nMax];
	fin>>n>>m;
	for(int i = 1; i <= n; i ++){
        rez[i] = 0;
        for(int j = 1; j <= m + 1; j ++){
            fin>>a[i][j];
        }
	}
	int i = 1, j = 1, k;
	while(i <= n && j <= m){
        for(k = i; k <= n; k ++){
            if(ABS(a[k][j]) > EPS){
                break;
            }
        }
        if(k == n + 1){
            ++ j;
            continue;
        }
        if(k != i){
            for(int l = 1; l <= m + 1; l ++){
                SWAP(a[i][l], a[k][l]);
            }
        }
        aux = a[i][j];
        for(int l = j; l <= m + 1; l ++){
            a[i][l] /= aux;
        }
        for(int u = i + 1; u <= n; u ++){
            aux = a[u][j];
            for(int l = j; l <= m + 1; l ++){
                a[u][l] -= a[i][l] * aux;
            }
        }
        ++ i;
        ++ j;
	}
	for(int i = n; i > 0; i --){
        for(int j = 1; j <= m + 1; j ++){
            if(ABS(a[i][j]) > EPS){
                if( j == m + 1){
                    fout<<"Imposibil\n";
                    return 0;
                }
                rez[j] = a[i][m + 1];
                for(int l = j + 1; l <= m; l ++){
                    rez[j] -= rez[l] * a[i][l];
                }
                break;
            }
        }
	}
	for(int i = 1; i <= m; i ++){
        fout<<fixed<<setprecision(8)<<rez[i]<<" ";
	}
	return 0;
}
