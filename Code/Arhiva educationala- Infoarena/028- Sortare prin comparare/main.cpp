#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>

#define nMax 500003
#define INF 2000003

#define SWAP(a, b) (v[0] = v[a], v[a] = v[b], v[b] = v[0])

using namespace std;

ifstream fin("algsort.in");
ofstream fout("algsort.out");

int n;
int v[nMax];

void Isort(int lo, int hi){
    for(int i = lo; i < hi; i ++){
        for(int j = i + 1 ; j > lo && v[j - 1] > v[j]; j --){
            SWAP(j - 1, j);
        }
    }
    return;
}

void partition(int lo, int hi, int &lp, int &rp){
    rp = lo + (rand() % (hi - lo + 1));
    SWAP(rp, hi);
    lp = lo + (rand() % (hi - lo));
    SWAP(lo, lp);
    rp = hi;
    lp = lo;
    if(v[lp] > v[rp]){
        SWAP(lp, rp);
    }
    ++ lo, -- hi;
    int i = lo;
    while(i <= hi){
        if(v[lp] > v[i]){
            SWAP(lo, i);
            ++ lo;
        }
        else{
            if(v[i] >= v[rp]){
                while(v[hi] > v[rp] && i < hi){
                    -- hi;
                }
                SWAP(i, hi);
                -- hi;
                if(v[lp] > v[i]){
                    SWAP(lo, i);
                    ++ lo;
                }
            }
        }
        ++ i;
    }
    SWAP(lo - 1, lp);
    SWAP(rp, hi + 1);
    lp = lo - 1;
    rp = hi + 1;
    return;
}

void DualPivotQuickSort(int lo, int hi){
    if(hi - lo < 20){
        Isort(lo, hi);
        return;
    }
    int lp, rp;
    partition(lo, hi, lp, rp);
    DualPivotQuickSort(lo, lp - 1);
    DualPivotQuickSort(lp + 1, rp - 1);
    DualPivotQuickSort(rp + 1, hi);
    return;
}


int main(){
    fin>>n;
    for(int i = 1; i <= n; i ++){
        fin>>v[i];
    }
    DualPivotQuickSort(1, n);
    for(int i = 1; i <= n; i ++){
        fout<<v[i]<<" ";
    }
	return 0;
}

