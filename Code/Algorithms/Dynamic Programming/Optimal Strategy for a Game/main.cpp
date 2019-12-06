#include <iostream>
#include <fstream>

#define nMax 101

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

using namespace std;

ifstream fin("file.in");

int main(){
    int v[nMax], dp[nMax][nMax];
    int n, start, max_score, x, y;
	fin>>n;
	for(int i = 1; i <= n; i ++){
        fin>>v[i];
	}
	for(int i = 1; i <= n; i ++){
        dp[i][i] = v[i];
	}
	start = 3;
	if(n % 2 == 0){
        for(int i = 1; i < n; i ++){
            dp[i][i + 1] = MAX(v[i], v[i + 1]);
        }
        start = 4;
	}
	for(int j = start, k; j <= n; j += 2){
        for(int i = 1; i <= n - j + 1; i ++){
            k = j + i - 1;
            dp[i][k] = MAX(v[i] + MIN(dp[i + 1][k - 1], dp[i + 2][k]),
                           v[j] + MIN(dp[i + 1][k - 1], dp[i][k - 2]));
        }
	}
	cout<<dp[1][n];
	return 0;
}
