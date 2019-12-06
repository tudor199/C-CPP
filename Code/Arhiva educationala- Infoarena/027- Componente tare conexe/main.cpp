#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <fstream>

#define _1 first
#define _2 second

#define nMax 100003

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int n, m, nr_ordine = 0;
bool viz[nMax] = {};
vector < int > ord;
vector < vector < int > > v, rv;

void r_dfs(int nod){
    viz[nod] = true;
    v[v.size() - 1].push_back(nod);
    for(int i = 0; i < rv[nod].size(); i ++){
        if(!viz[rv[nod][i]]){
            r_dfs(rv[nod][i]);
        }
    }
    return;
}

void dfs(int nod){
    viz[nod] = true;
    for(int i = 0; i < v[nod].size(); i ++){
        if(!viz[v[nod][i]]){
            dfs(v[nod][i]);
        }
    }
    ord.push_back(nod);
    return;
}

void scc(){
    pair < int, int > now;
    for(int i = 1; i <= n; i ++){
        if(!viz[i]){
            dfs(i);
        }
    }
    v.clear();
    memset(viz, 0, sizeof(viz));
    for(int i = ord.size() - 1; i >= 0; i --){
        if(!viz[ord[i]]){
            v.resize(v.size() + 1);
            r_dfs(ord[i]);
        }
    }
    return;
}

int main(){
    int m;
    fin>>n>>m;
    v.resize(n + 1);
    rv.resize(n + 1);
    for(int i = 1, x, y; i <= m; i ++){
        fin>>x>>y;
        v[x].push_back(y);
        rv[y].push_back(x);
    }
    scc();
    fout<<v.size()<<"\n";
    for(int i = 0; i < v.size(); i ++){
        for(int j = 0; j < v[i].size(); j ++){
            fout<<v[i][j]<<" ";
        }
        fout<<"\n";
    }
    return 0;
}
