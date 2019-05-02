#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>

#define INF 1ll * 1000000000 * 1000000000
#define nMax 1000003

using namespace std;

ifstream fin("huffman.in");
ofstream fout("huffman.out");


int lg[nMax];
unsigned long long cod[nMax];
int n, k, p;
int q[2][nMax], l[2], r[2];
unsigned long long sum = 0, m;

class huffman{
public:
    int s[2];
    unsigned long long data;
}v[2 * nMax];

void dfs(int poz, int deep, unsigned long long code){
    if(!v[poz].s[0]){
        lg[poz] = deep;
        cod[poz] = code;
        return;
    }
    dfs(v[poz].s[0], deep + 1, code * 2);
    dfs(v[poz].s[1], deep + 1, code * 2 + 1);
    return;
}

int main(){
    fin>>n;
    for(int i = 1; i <= n; i ++){
        fin>>v[i].data;
        q[0][i] = i;
    }
    l[0] = l[1] = 1;
    r[0] = n; r[1] = 0;
    k = n;
    while(l[0] + l[1] <= r[0] + r[1]){
        ++ k;
        for(int i = 0; i < 2; i ++){
            p = 0;
            m = INF;
            for(int j = 0; j < 2; j ++){
                if(v[q[j][l[j]]].data <= m &&  l[j] <= r[j]){
                    p = j;
                    m = v[q[j][l[j]]].data;
                }
            }
            v[k].s[i] = q[p][l[p]];
            v[k].data += m;
            ++ l[p];
        }
        sum += v[k].data;
        q[1][++ r[1]] = k;
    }
    dfs(k, 0, 0);
    fout<<sum<<"\n";
    for(int i = 1; i <= n; i ++){
        fout<<lg[i]<<" "<<cod[i]<<"\n";
    }
    return 0;
}
