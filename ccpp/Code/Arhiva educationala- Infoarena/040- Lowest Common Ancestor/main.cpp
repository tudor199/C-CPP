#include <iostream>
#include <vector>
#include <fstream>

#define nMax 100003
#define lMax 20

#define MINLVL(a, b) (lvl[a] < lvl[b] ? a : b)

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

int n, m, counter, x, y;
int rmq[lMax][2 * nMax], log[2 * nMax], lvl[nMax], first[nMax];
vector < int > v[nMax];
vector < bool > viz(nMax, false);

void dfs(int nod){
    rmq[0][++counter] = nod;
    for(auto x : v[nod]){
        if(lvl[x] == -1){
            lvl[x] = lvl[nod] + 1;
        }
        dfs(x);
        rmq[0][++counter] = nod;
    }
    return;
}

void make_rmq(){
    log[1] = 0;
    int nm = 2 * n - 1;
    for(int i = 2; i <= nm; i++){
        log[i] = log[i / 2] + 1;
    }
    for(int i = 1, exp; i <= log[nm]; i++){
        exp = 1 << (i - 1);
        for(int j = 1; j <= nm - ((1 << i) - 1); j++){
            rmq[i][j] = MINLVL(rmq[i - 1][j], rmq[i - 1][j + exp]);
        }
    }
    return;
}

int querry(int a, int b){
    (a < b ? (x = a, y =b) : (x = b, y = a));
    int dif = y - x + 1;
    int exp = log[dif];
    int sh =  dif - (1 << exp);
    return MINLVL(rmq[exp][x], rmq[exp][x + sh]);
}

int main(){
    fin>>n>>m;
    for(int i = 2, tt; i <= n; i++){
        fin>>tt;
        v[tt].push_back(i);
    }
    lvl[1] = 0;
    for(int i = 2; i <= n; i++){
        lvl[i] = -1;
    }
    counter = 0;
    dfs(1);
    for(int i = 1; i <= 2*n -1; i++){
        if(!first[rmq[0][i]]){
            first[rmq[0][i]] = i;
        }
    }
    make_rmq();
    for(int i = 1; i <= m; i++){
        fin>>x>>y;
        fout<<querry(first[x], first[y])<<"\n";
    }
	return 0;
}
