#include <iostream>
#include <cstring>
#include <fstream>

#define nMax 101

using namespace std;

ifstream fin("file.in");

int min(int a, int b, int c){
    return min(min(a, b), c);
}

int main(){
    char a[nMax], b[nMax];
    int dp[nMax][nMax], n, m;
	fin>>a>>b;
	n = strlen(a);
	m = strlen(b);
	for(int i = 0; i < n; i ++){
        dp[i][0] = i;
	}
	for(int j = 0; j < m; j ++){
        dp[0][j] = j;
	}
	for(int i = 1; i < n; i ++){
        for(int j = 1; j < m; j ++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
	}
	cout<<dp[n - 1][m - 1];
	return 0;
}
