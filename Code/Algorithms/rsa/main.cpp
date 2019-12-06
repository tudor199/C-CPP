#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define prim1 113
#define prim2 191

// #define phi (prim1 - 1) * (prim2 - 1)
#define MOD prim1 * prim2

using namespace std;
long long gcd(long long a, long long b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}


const long long phi = (prim1 - 1) * (prim2 - 1) / gcd(prim1 - 1, prim2 - 1);



long long inv_mod( long long a1, const long long mod){
    long long a0 = mod, b0 = mod, b1 = 1, div, man;
    while(a1 > 1){
        div = a0 / a1;
        man = a0;
        a0 = a1;
        a1 = man - a1 * div;
        man = b0;
        b0 = b1;
        b1 = man - b1 * div;
    }
    if(a1 == 1){
        if(b1 < 0)
            b1 += (b1 / mod * -1 + 1) * mod;
        return b1 % mod;
    }
    return 0;
}

long long lgpow(long long a, long long b){
    if(b == 1){
        return a;
    }
    int rez = lgpow(a, b / 2);
    rez = (rez * rez) % MOD;
    if(b & 1){
        rez = (rez * a) % MOD;
    }
    return rez;
}

int main()
{
    ranlux24 rd(time(NULL));
    long long e, d, now;
    while(true){
        now = rd();
        cout<<now<<" --- ";
        now %= phi;
        cout<<now<<"\n";
        if(gcd(now, phi) == 1){
            e = now;
            break;
        }
    }
    d = inv_mod(e, phi);
    cout<<"\n\n\n"<<phi<<"\n"<<e<<"\n"<<d<<"\n\n\n";
    int test1, test2, test3;
    test1 = rd() % phi;
    test2 = lgpow(test1, e);
    test3 = lgpow(test2, d);
    cout<<test1<<" --- "<<test2<<" --- "<<test3<<"\n";
    return 0;
}
