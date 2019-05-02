#include <iostream>
#include <fstream>

#define nMax 100003

#define MAX(a,b) (a > b ? a : b)

using namespace std;

ifstream fin("arbint.in");
ofstream fout("arbint.out");

int v[3 * nMax];

void update(int nod, int st, int dr, int val, int x, int y){
    if(st == dr){
        v[nod] = val;
        return;
    }
    int mid = (st + dr) / 2;
    if(x <= mid){
        update(2 * nod, st, mid, val, x, y);
    }
    if(mid < y){
        update(2 * nod + 1, mid + 1, dr, val, x, y);
    }
    v[nod] = MAX(v[2 * nod], v[2 * nod + 1]);
    return;
}

int querry(int nod, int st, int dr, int x, int y){
    if(x <= st && dr <= y){
        return v[nod];
    }
    int m1 = 0, m2 = 0, mid = (st + dr) / 2;
    if(x <= mid){
        m1 = querry(2 * nod, st, mid, x, y);
    }
    if(mid < y){
        m2 = querry(2 * nod + 1, mid + 1, dr, x, y);
    }
    return MAX(m1, m2);
}

int main(){
	int n, m, cerinta, x, y;
	fin>>n>>m;
	for(int i = 1; i <= n; i++){
        fin>>x;
        update(1, 1, n, x, i, i);
	}
	for(int i = 1; i <= m; i++){
        fin>>cerinta>>x>>y;
        if(cerinta == 0){
            fout<<querry(1, 1, n, x, y)<<"\n";
        }
        else{
            update(1, 1, n, y, x, x);
        }
	}
	return 0;
}
