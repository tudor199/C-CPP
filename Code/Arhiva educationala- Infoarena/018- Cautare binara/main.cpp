#include <iostream>
#include <fstream>

#define nMax 100003

using namespace std;

ifstream fin("cautbin.in");
ofstream fout("cautbin.out");

int main(){
	int n, m, cerinta, val, x, y, mid;
    int v[nMax];
	fin>>n;
	v[n + 1] =(1LL << 31) -1;
	for(int i = 1; i <= n; i++){
        fin>>v[i];
	}
	fin>>m;
	for(int i = 1; i <= m ; i++){
        fin>>cerinta>>val;
        x = 1, y = n;
        if(cerinta == 2){
            val--;
        }
        while(x != y){
            mid = (x + y) / 2;
            (v[mid + 1] <= val) ? (x = mid + 1) : (y = mid);
        }
        if(cerinta == 0){
            fout<<(v[x] == val ? x : -1)<<"\n";
        }
        else{
            if(cerinta == 1){
                fout<<x + (v[x + 1] <= val)<<"\n";
            }
            else{
                fout<<(v[x] >= val + 1 ? 1 : (x + 1))<<"\n";
            }
        }
	}
	return 0;
}
