#include <iostream>
#include <vector>
#include <fstream>

#define nMax 100001

using namespace std;

ifstream fin("darb.in");
ofstream fout("darb.out");

vector < int > v[nMax];
int dmax;
int dist[nMax];
bool viz[nMax];

void dfs(int nod){
    if(viz[nod]){
        return;
    }
    viz[nod] = true;
    dist[dmax] = nod;
    for(int i = 0; i < v[nod].size(); i++){
        dmax++;
        dfs(v[nod][i]);
        dmax--;
    }
    return;
}

int main(){
    int n, x, y;
    fin>>n;
    for(int i = 1; i <= n; i++){
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(x);
    for(int i = n - 1; i >= 0; i--){
        if(dist[i]){
            x = dist[i];
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    dfs(x);
    for(int i = n - 1; i >= 0; i--){
        if(dist[i]){
            fout<<i + 1;
            break;
        }
    }
    return 0;
}
