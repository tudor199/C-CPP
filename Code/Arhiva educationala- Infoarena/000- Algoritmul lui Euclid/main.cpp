#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int x, int y){
    if(!y){
        return x;
    }
    return euclid(y, x % y);
}

int main(){
	int n, x, y;
	fin>>n;
	for(int i = 1; i <= n; i++){
        fin>>x>>y;
        fout<<euclid(x, y)<<"\n";
	}
	return 0;
}
