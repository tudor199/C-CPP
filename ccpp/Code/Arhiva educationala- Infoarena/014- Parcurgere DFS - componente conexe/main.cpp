#include <iostream>
#include <vector>
#include <fstream>

#define nMax 100003

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

vector < int > v[nMax];
vector < bool > viz(nMax, false);

void dfs(int nod){
    for(auto x : v[nod]){
        if(!viz[x]){
            viz[x] = true;
            dfs(x);
        }
    }
    return;
}

int main(){
    int n, m, nrconexe;
    fin>>n>>m;
    for(int i = 1,x , y; i <= m; i++){
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    nrconexe = 0;
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            viz[i] = true;
            nrconexe++;
            dfs(i);
        }
    }
    fout<<nrconexe<<"\n";
	return 0;
}
