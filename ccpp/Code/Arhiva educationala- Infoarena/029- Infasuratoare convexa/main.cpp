#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>

#define x first
#define y second

#define INF 2000000000
#define nMax 120003

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

bool remove(pair < double, double > a, pair < double, double > b, pair < double, double > c){
    return ((b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x)) > 0;
}

pair < double, double > point[nMax], stack[nMax];

int main(){
    int n, m;
    fin>>n;
    for(int i = 0; i < n; i ++){
        fin>>point[i].x>>point[i].y;
    }
    sort(point, point + n);
    stack[0] = point[0];
    stack[1] = point[1];
    m = 1;
    for(int i = 2; i < n; i ++){
        while(m && remove(stack[m - 1], stack[m], point[i])){
            -- m;
        }
        stack[++ m] = point[i];
    }
    stack[++ m] = point[n - 2];
    for(int i = n - 3; i >= 0; i --){
        while(m && remove(stack[m - 1], stack[m], point[i])){
            -- m;
        }
        stack[++ m] = point[i];
    }
    fout<<m<<"\n"<<fixed<<setprecision(6);
    for(int i = 0; i < m; i ++){
        fout<<stack[i].x<<" "<<stack[i].y<<"\n";
    }
	return 0;
}
