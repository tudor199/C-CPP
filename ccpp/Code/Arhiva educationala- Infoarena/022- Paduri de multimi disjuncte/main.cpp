#include <iostream>
#include <vector>
#include <fstream>

#define nMax 100003

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");
int root[nMax];

int find(int x){
    if(root[x] == x){
        return x;
    }
    return (root[x] = find(root[x]));
}

void merge(int x, int y){
    root[find(x)] = find(y);
    return;
}


int main(){
	int n, m, o, x, y;
	fin>>n>>m;
	for(int i = 1; i <= n; i ++){
        root[i] = i;
	}
	while(m --){
        fin>>o>>x>>y;
        if(o == 1){
            if(find(x) != find(y)){
                merge(x, y);
            }
        }
        else{
            if(find(x) == find(y)){
                fout<<"DA\n";
            }
            else{
                fout<<"NU\n";
            }
        }
	}
	return 0;
}
