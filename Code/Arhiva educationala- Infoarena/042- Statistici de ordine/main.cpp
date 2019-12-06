#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define nMax 3000003

using namespace std;

ifstream fin("sdo.in");
ofstream fout("sdo.out");

int v[nMax];

int partition(int lo, int hi){
    int pivot = lo + (rand() % (hi - lo + 1));
    swap(v[pivot], v[hi]);
    pivot = hi;
    while(lo < pivot){
        if(v[lo] >= v[pivot]){
            swap(v[lo], v[pivot - 1]);
            swap(v[pivot - 1], v[pivot]);
            -- pivot;
        }
        else{
            ++ lo;
        }
    }
    return pivot;
}

int sdo(int lo, int hi, int k){
    int pivot = partition(lo, hi);
    if(pivot == k){
        return v[pivot];
    }
    if(pivot < k){
        return sdo(pivot + 1, hi, k);
    }
    else{
        return sdo(lo, pivot - 1, k);
    }
}

int main(){
    srand(time(NULL));
    int n, k;
	fin>>n>>k;
	for(int i = 1; i <= n; i ++){
        fin>>v[i];
	}
	fout<<sdo(1, n, k);
	return 0;
}
