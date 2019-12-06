#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <fstream>

#define nMax 200003

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

class aux{
public:
    pair < int, int > mu;
    int  cost;
    aux() : mu(make_pair(0, 0)), cost(0) {}
    aux(pair < int, int > _mu, int _cost) : mu(_mu), cost(_cost) {}
private:
}now;

int n, m, x, y, sumcost;
int cc[nMax];
vector < aux > v, rez;

bool mycomp(aux a, aux b){
    return a.cost < b.cost;
}

int find(int x){
    if(x == cc[x]){
        return x;
    }
    return cc[x] = find(cc[x]);
}

void merge(int x, int y){
    cc[find(x)] = cc[find(y)];
    return;
}

int main(){
    aux now;
    fin>>n>>m;
    while(m--){
        fin>>x>>y>>sumcost;
        v.push_back(aux (make_pair(x, y), sumcost));
    }
    sort(v.begin(), v.end(), mycomp);
    for(int i = 1; i <= n; i++){
        cc[i] = i;
    }
    sumcost = 0;
    for(int i = 0; rez.size() < n - 1; i ++){
        now = v[i];
        if(find(now.mu.first) == find(now.mu.second)){
            continue;
        }
        sumcost += now.cost;
        rez.push_back(now);
        merge(now.mu.first, now.mu.second);
    }
    fout<<sumcost<<"\n"<<n - 1<<"\n";
    for(auto x : rez){
        fout<<x.mu.first<<" "<<x.mu.second<<"\n";
    }
    return 0;
}
