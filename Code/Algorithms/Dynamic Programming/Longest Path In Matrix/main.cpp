#include <iostream>
#include <fstream>

#define nMax 103

using namespace std;

ifstream fin("file.in");

int v[nMax][nMax], dp[nMax][nMax] = {};
int n, m;

inline max(int d[4], int dn){
    int max_d = d[0];
    for(int i = 1; i < dn; i ++){
        if(max_d < d[i]){
            max_d = d[i];
        }
    }
    return (1 + max_d);
}

int longestpath(int i, int j){
    if(dp[i][j]){
        return dp[i][j];
    }
    int d[4] = {},dn = 0;
    if(i > 1 && v[i - 1][j] > v[i][j]){
        d[dn ++] = longestpath(i - 1, j);
    }
    if(i < n && v[i + 1][j] > v[i][j]){
        d[dn ++] = longestpath(i + 1, j);
    }
    if(j > 1 && v[i][j - 1] > v[i][j]){
        d[dn ++] = longestpath(i, j - 1);
    }
    if(j < m && v[i][j + 1] > v[i][j]){
        d[dn ++] = longestpath(i, j + 1);
    }
    if(!dn){
        dp[i][j] = 1;
    }
    else{
        dp[i][j] = max(d, dn);
    }
    return dp[i][j];
}

int main(){
    int rez = 1;
    fin>>n>>m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            fin>>v[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(dp[i][j]){
                continue;
            }
            dp[i][j] = longestpath(i, j);
            rez = max(rez, dp[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<rez;
	return 0;
}
