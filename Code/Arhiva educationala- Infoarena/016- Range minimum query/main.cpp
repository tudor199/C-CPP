#include <iostream>
#include <fstream>

#define nMax 100003
#define lMax 19

#define MIN(a, b) (a < b ? a : b)

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");
int rmq[lMax][nMax];
int main(){
    int n, m, x, y, dif, exp;
    int log[nMax];
	fin>>n>>m;
	log[1] = 0;
	for(int i = 2; i <= n; i++){
        log[i] = log[i / 2] + 1;
	}
	for(int i = 1; i <= n; i++){
        fin>>rmq[0][i];
	}
	for(int i = 1; i <= log[n]; i++){
        exp = 1 << (i - 1);
        for(int j = 1; j <= n - (1 << i)  + 1; j++){
            rmq[i][j] = MIN(rmq[i - 1][j], rmq[i - 1][j + exp]);
        }
	}
	for(int i = 1; i <= m; i++){
        fin>>x>>y;
        dif = y - x + 1;
        exp = log[dif];
        fout<<MIN(rmq[exp][x], rmq[exp][x + dif - (1 << exp)])<<"\n";
	}
	return 0;
}
