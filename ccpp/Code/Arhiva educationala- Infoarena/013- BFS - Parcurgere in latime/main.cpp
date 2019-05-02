#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

#define nMax 100003

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

int main(){
    int n, m, start, now, x, y, cost[nMax];
    vector < int > v[nMax];
    queue < int > q;
    fin>>n>>m>>start;
	for(int i = 1; i <= m; i++){
        fin>>x>>y;
        v[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
        cost[i] = -1;
	}
	cost[start] = 0;
	q.push(start);
	while(!q.empty()){
        now = q.front();
        for(auto x : v[now]){
            if(cost[x] == -1){
                q.push(x);
                cost[x] = cost[now] + 1;
            }
        }
        q.pop();
    }
    for(int i = 1; i <=n ; i++){
        fout<<cost[i]<<" ";
    }
    fin.close();
    fout.close();
	return 0;
}
