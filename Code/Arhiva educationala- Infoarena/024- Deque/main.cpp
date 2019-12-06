#include <iostream>
#include <deque>
#include <fstream>

#define nMax 5000003

using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

int n, k, v[nMax], dq[nMax], bk, fr;
long long sum = 0;

int main(){
    fin>>n>>k;
	for(int i = 1; i <= n; i ++){
        fin>>v[i];
	}
	bk = 1, fr = 0;
	for(int i = 1; i <= n; i ++){
        while(bk <= fr && v[i] <= v[dq[fr]]){
            -- fr;
        }
        dq[++ fr] = i;
        if(dq[bk] == i - k){
            ++ bk;
        }
        if(i >= k){
            sum += v[dq[bk]];
        }
	}
    fout<<sum<<"\n";
	return 0;
}
