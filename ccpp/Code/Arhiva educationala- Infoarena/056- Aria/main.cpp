#include <iostream>
#include <iomanip>
#include <fstream>

#define nMax 100003

#define x first
#define y second

using namespace std;

ifstream fin("aria.in");
ofstream fout("aria.out");

int main(){
    double A = 0;
	pair < double, double > point[nMax];
	int n;
	fin>>n;
	for(int i = 0; i < n; i ++){
        fin>>point[i].x>>point[i].second;
	}
	point[n] = point[0];
	for(int i = 0; i < n; i ++){
        A += (point[i].x * point[i + 1].y - point[i + 1].x * point[i].y);
	}
	A /= 2;
	fout<<fixed<<setprecision(6)<<A;
	return 0;
}
