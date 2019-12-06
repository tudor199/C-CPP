#include <iostream>
#include <cstdio>
#include <queue>
#include <fstream>

#define nMax 50003

using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

int main(){
	int n, m, x, y, now;
    vector < int > dext(nMax, 0), v[nMax];
    queue < int > d0;
    fin>>n>>m;
    for(int i = 1; i <= m; i++){
        fin>>x>>y;
        v[x].push_back(y);
        dext[y]++;
    }
    for(int i = 1; i <= n; i++){
        if(!dext[i]){
            d0.push(i);
        }
    }
    while(!d0.empty()){
        now = d0.front();
        fout<<now<<" ";
        d0.pop();
        for(auto x: v[now]){
            dext[x]--;
            if(!dext[x]){
                d0.push(x);
            }
        }
    }
	return 0;
}
