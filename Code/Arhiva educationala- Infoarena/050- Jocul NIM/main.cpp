#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main(){
	int T, n, nim_sum, x;
	fin>>T;
	while(T --){
        fin>>n;
        nim_sum = 0;
        for(int i = 1; i <= n; i ++){
            fin>>x;
            nim_sum ^= x;
        }
        if(nim_sum){
            fout<<"DA\n";
        }
        else{
            fout<<"NU\n";
        }
	}
	return 0;
}
