#include <iostream>
#include <fstream>

#define nMax 6000003

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

int v[nMax];

int main(){
	int n, sum = -1, bi, beg, end, maxsum = -2147483648;
    fin>>n;
    for(int i = 1; i <= n; i ++){
        fin>>v[i];
    }
    for(int i = 1; i <= n; i ++){
        if(sum < 0){
            sum = v[i];
            bi = i;
        }
        else{
            sum += v[i];
        }
        if(sum > maxsum){
            maxsum = sum;
            beg = bi;
            end = i;
        }
    }
    fout<<maxsum<<" "<<beg<<" "<<end<<"\n";
	return 0;
}
