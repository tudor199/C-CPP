#include <iostream>
#include <fstream>
#include <vector>

#define MOD 25000

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

vector < int > hs[MOD];


bool is_inhs(int x){
    for(int i = 0; i < hs[x % MOD].size(); i++){
        if(hs[x % MOD][i] == x){
            return 1;
        }
    }
    return 0;
}

void inserths(int x){
    if(is_inhs(x)){
        return;
    }
    hs[x % MOD].push_back(x);
    return;
}

void removehs(int x)
{
    for(int i = 0; i < hs[x % MOD].size(); i++){
        if(hs[x % MOD][i] == x){
            hs[x % MOD].erase(hs[x % MOD].begin() + i);
            return;
        }
    }
    return;
}

int main(){
    char buffer[2000003];
    int bufferi = 0;
    int var, x, n;
    fin>>n;
    for(int i = 1; i <= n; i++){
        fin>>var>>x;
        switch(var){
        case 1:
            inserths(x);
            break;
        case 2:
            removehs(x);
            break;
        default:
            buffer[bufferi++] = '0' + is_inhs(x);
            buffer[bufferi++] = '\n';
            break;
        }
    }
    fout<<buffer;
    return 0;
}
