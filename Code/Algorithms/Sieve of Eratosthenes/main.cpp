#include <iostream>
#include <fstream>

#define nMax 20000003

using namespace std;

ifstream fin("file.in");

bool v[nMax] = {};
int sieve(int n){
    int nr_p = n/2 + (n % 2);
    for(int i = 3; i * i <= n; i += 2){
        if(v[i] == false){
            for(int j = i; i * j <= n; j += 2){
                if(v[i * j] == false){
                    -- nr_p;
                    v[i * j] = true;
                }
            }
        }
    }
    return nr_p;
}

int main(){
    int n;
	fin>>n;
	cout<<sieve(n)<<"\n";
	return 0;
}
