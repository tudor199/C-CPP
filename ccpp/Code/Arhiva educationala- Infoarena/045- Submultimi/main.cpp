#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

int main(){
    int n;
    fin>>n;
	for(int idx = 1; idx < 1 << n; idx++){
        for(int j = 1; j <= n; j++){
            if(idx & (1 << (j - 1))){
                fout<<j<<" ";
            }
        }
        fout<<"\n";
	}
	return 0;
}
