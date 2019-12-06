#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>

#define nMax 100003
#define INF 1e18

#define x first
#define y second

#define POW2(a) (1ll * (a) * (a))
#define DIST(a, b) (1ll * (1ll *(a.x - b.x) * (a.x - b.x) + 1ll *(a.y - b.y) * (a.y - b.y)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a, b) (P[0] = (a), (a) = (b), (b) = P[0])

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

pair < int, int > temp[nMax];

int partition_x(pair < int, int > P[nMax], int lo, int hi){
    int pivot = lo + (rand() % (hi - lo + 1));
    SWAP(P[pivot], P[hi]);
    pivot = hi;
    while(lo < pivot){
        if(P[lo].x >= P[pivot].x){
            SWAP(P[lo], P[pivot - 1]);
            SWAP(P[pivot - 1], P[pivot]);
            -- pivot;
        }
        else{
            ++ lo;
        }
    }
    return pivot;
}

void qsort_x(pair < int, int > P[nMax], int lo, int hi){
    if(lo >= hi){
        return;
    }
    int pivot = partition_x(P, lo, hi);
    qsort_x(P, lo, pivot - 1);
    qsort_x(P, pivot + 1, hi);
    return;
}

bool cmp_y(pair < int, int > a, pair < int, int > b){
    return a.y < b.y;
}

long long closest_dist(pair < int, int > P[nMax], int lo, int hi){
    if(hi - lo == 0){
        return INF;
    }
    if(hi - lo == 1){
        if(P[lo].y > P[hi].y){
            SWAP(P[lo], P[hi]);
        }
        return DIST(P[lo], P[hi]);
    }
    int mid = (lo + hi) / 2,
        xmid = P[mid].x;
    long long   left = closest_dist(P, lo, mid),
                right = closest_dist(P, mid + 1, hi),
                d = MIN(left, right);
    merge(P + lo, P + mid + 1, P + mid + 1, P + hi + 1, temp, cmp_y);
    copy(temp, temp + hi - lo + 1, P + lo);
    int nl = 0, nr = 50000;
    for(int i = 0, n = hi - lo + 1; i < n; i ++){
        P[lo + i] = temp[i];
        if(POW2(xmid - temp[i].x) < d){
            if(xmid - temp[i].x >= 0){
                temp[nl ++] = temp[i];
            }
            else{
                temp[nr ++] = temp[i];
            }
        }
    }
    int il = 0, ir = 50000;
    while(il < nl && ir < nr){
        if(temp[il].y < temp[ir].y){
            for(int i = ir; POW2(temp[il].y - temp[i].y) < d && i < nr; i ++){
                d = MIN(d, DIST(temp[il], temp[i]));
            }
            ++ il;
        }
        else{
            for(int i = il; POW2(temp[ir].y - temp[i].y) < d && i < nl; i ++){
                d = MIN(d, DIST(temp[ir], temp[i]));
            }
            ++ ir;
        }
    }
    return d;
}

int main(){
    int n;
    pair < int, int > P[nMax];
    fin>>n;
    for(int i = 1; i <= n; i ++){
        fin>>P[i].x>>P[i].y;
    }
    qsort_x(P, 1, n);
    fout<<fixed<<setprecision(6)<<sqrt(closest_dist(P, 1, n))<<"\n";
	return 0;
}
