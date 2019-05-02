#include <iostream>
#include <fstream>

#define nMax 200003
#define INF 2000000000

#define SWAP(a, b) (h[0] = a, a = b, b = h[0])

using namespace std;

ifstream fin("heapuri.in");
ofstream fout("heapuri.out");

int h1[nMax], n_h1 = 0, h2[nMax / 2], n_h2 = 0;
int ord[nMax], n_ord = 0;

void add(int *h, int &n, int x){
    int nod = ++ n;
    h[nod] = x;
    while(nod != 1 && h[nod] < h[nod / 2]){
        SWAP(h[nod], h[nod / 2]);
        nod /= 2;
    }
    return;
}

void remove_top(int *h, int &n){
    int minim, nod = 1;
    h[1] = h[n --];
    while(true){
        if(2 * nod > n){
            break;
        }
        if(2 * nod == n){
            minim = 2 * nod;
        }
        else{
            minim = (h[2 * nod] < h[2 * nod + 1] ? (2 * nod) : (2 * nod + 1));
        }
        if(h[nod] < h[minim]){
            break;
        }
        SWAP(h[nod], h[minim]);
        nod = minim;
    }
    return;
}

int top(){
    while(h1[1] == h2[1]){
        remove_top(h1, n_h1);
        remove_top(h2, n_h2);
    }
    return h1[1];
}

int main(){
    int n, o , x;
	fin>>n;
	while(n --){
        fin>>o;
        switch(o){
        case 1:
            fin>>x;
            ord[++ n_ord] = x;
            add(h1, n_h1, x);
            break;
        case 2:
            fin>>x;
            add(h2, n_h2, ord[x]);
            break;
        default:
            fout<<top()<<"\n";
            break;
        }
	}
	return 0;
}
