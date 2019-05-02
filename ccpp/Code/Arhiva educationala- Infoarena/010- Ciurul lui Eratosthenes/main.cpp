#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

#define nMax 2000003

using namespace std;

ifstream fin("ciur.in");
ofstream fout("ciur.out");

vector < bool > v(nMax,false);

int erasthenes(int n)
{
    int prim = 1;
    for(int i = 3, m = sqrt(n); i <= m; i += 2)
        if(!v[i])
            for(int j = 2; i * j <= n; j++)
                v[i * j]=true;
    for(int i = 3; i <= n; i += 2)
        if(!v[i])
            prim++;
    return prim;
}

int main()
{
    int n;
    fin>>n;
    fout<<erasthenes(n)<<"\n";
    return 0;
}
