#include <iostream>
#include <fstream>

#define ABS(a) ((a) < 0 ? -(a) : a)

#define nMax 17

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

int st[nMax], n, nr_sol = 0;
bool col[2 * nMax], dp[2 * nMax], ds[2 * nMax];

bool OK(int k){
    for(int i = 1; i < k; i ++){
        if(st[i] == st[k] || (k - i) == ABS(st[k] - st[i])){
            return false;
        }
    }
    return true;
}

void afisare(int n){
    for(int i = 1; i <= n; i ++){
        fout<<st[i]<<" ";
    }
    fout<<"\n";
    return;
}

void bk(int k){
    if(k == n + 1){
        if(!nr_sol){
            afisare(n);
        }
        ++ nr_sol;
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(!col[i] && !dp[i + n - k] && !ds[k + i - 1]){
            col[i] = dp[i + n - k] = ds[k + i - 1] = true;
            st[k] = i;
            bk(k + 1);
            col[i] = dp[i + n - k] = ds[k + i - 1] = false;
        }
    }
    return;
}

int main(){
    fin>>n;
    bk(1);
    fout<<nr_sol;
	return 0;
}
