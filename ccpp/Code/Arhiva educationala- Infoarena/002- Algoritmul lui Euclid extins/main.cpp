#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

int cmmdc(int a,int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x0, y0;
    int d = cmmdc(b, a % b, x0, y0);
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
}

int main(){
	int n, a, b, c, d, x, y;
	fin>>n;
	for(int i = 1; i <= n; i ++){
        fin>>a>>b>>c;
        d=cmmdc(a, b, x, y);
        cout<<c<<"    "<<d<<"|||";
        if(c % d){
            x = 0;
            y = 0;
        }
        cout<<x * (c / d)<<" "<<y * (c / d)<<"\n";
	}
	return 0;
}
