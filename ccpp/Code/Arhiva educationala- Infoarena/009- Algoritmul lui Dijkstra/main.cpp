#include <iostream>
#include <queue>
#include <fstream>

#define nMax 50003
#define INF 2000000000

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

class aux{
public:
    int to, cost;
    aux(): to(0), cost(0) {}
    aux(int _to, int _cost): to(_to), cost(_cost) {}
    bool operator()(aux a, aux b){
        return (a.cost > b.cost);
    }
private:
};

int dij[nMax];
vector < aux > v[nMax];
priority_queue< aux, vector < aux >, aux > q;

int main(){
    aux now;
	int n, m, x , y, val;
	fin>>n>>m;
	for(int i = 1; i <= m; i++){
        fin>>x>>y>>val;
        v[x].push_back(aux(y, val));
	}
	for(int i = 1; i <= n; i++){
        dij[i] = INF;
	}
	q.push(aux(1, 0));
	while(!q.empty()){
        now = q.top();
        q.pop();
        if(dij[now.to] <= now.cost){
            continue;
        }
        dij[now.to] = now.cost;
        for(auto x : v[now.to]){
            x.cost += dij[now.to];
            q.push(x);
        }
	}
	for(int i = 2; i <= n; i++){
        fout<<(dij[i] == INF ? 0 : dij[i])<<" ";
	}
	return 0;
}
