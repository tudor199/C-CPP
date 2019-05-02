#include <iostream>
#include <fstream>

#define nMax 103
#define sMax 1003

using namespace std;

ifstream fin("file.in");

int main(){
    int n, sum;
    int v[nMax];
    bool dp[nMax][sMax];
	fin>>n>>sum;
	for(int i = 1; i <= n; i ++){
        fin>>v[i];
	}
	for(int i = 0; i <= n; i ++){
        dp[i][0] = true;
	}
	for(int i = 1; i <= sum; i ++){
        dp[0][i] = false;
	}

	for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= sum; j ++){
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i]];
        }
	}
	cout<<dp[n][sum];
	return 0;
}
