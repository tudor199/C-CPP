#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <fstream>

#define nMax 1000003
#define MOD 9973

using namespace std;

ifstream fin("ssnd.in");
ofstream fout("ssnd.out");

bitset < nMax > viz;
vector < int > prim;

void erastothenes(int n){
    for(int i = 3, sqrtn = sqrt(n); i <= sqrtn; i += 2){
        if(!viz[i]){
            for(int j = i + 1; i * j <= n; j ++){
                viz[i * j] = true;
            }
        }
    }
    prim.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!viz[i]){
            prim.push_back(i);
        }
    }
    return;
}

long long inv_mod(long long a1){
    long long a0 = MOD, b0 = MOD, b1 = 1, man, q;
    while(a1 > 1){
        q = a0 / a1;
        man = a1;
        a1 = a0 - q * a1;
        if(a1 < 0){
            a1 = MOD - ((-a1) % MOD);
        }
        a0 = man;
        man = b1;
        b1 = b0 - q * b1;
        if(b1 < 0){
            b1 = MOD - ((-b1) % MOD);
        }
        b0 = man;
    }
    if(a1 == 1){
        return b1;
    }
    return -1;
}

long long lgpow(long long a, long long b){
    if(b == 1){
        return a;
    }
    long long rez = lgpow(a, b >> 1);
    rez = (rez * rez) % MOD;
    if(b & 1){
        return (rez * a) % MOD;
    }
    return rez;
}

int main(){
	int T,nrdiv;
	long long n, sum, now, inv;
	vector < pair < int, int > > div;
	erastothenes(1000000);
	fin>>T;
	while(T--){
        fin>>n;
        for(int i = 0; i < prim.size() && 1ll * prim[i] * prim[i] <= n; i++){
            if(n % prim[i] == 0){
                inv = 0;
                div.push_back(make_pair(prim[i], 0));
                while(n % prim[i] == 0){
                    div.back().second++;
                    n /= prim[i];
                }
            }
        }
        if(n != 1){
            div.push_back(make_pair(n, 1));
        }
        nrdiv = 1;
        sum = 1;
        for(auto x : div){
            nrdiv *= x.second + 1;
            now = lgpow(x.first, x.second + 1) - 1;
            inv = inv_mod(x.first - 1);
            now = (now * inv) % MOD;
            sum = (sum * now) % MOD;
            if(sum < 0){
                sum = MOD - ((-sum) % MOD);
            }
        }
        fout<<nrdiv<<" "<<sum<<"\n";
        div.clear();
	}
	return 0;
}
