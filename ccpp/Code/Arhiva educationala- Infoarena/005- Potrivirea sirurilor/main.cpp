#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>

#define nMax 2000001

#define MIN(a, b) (a < b ? a : b)

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

char pat[nMax],txt[nMax];
int  v[nMax], loc[1003], locn = 0;

void print(){
	fout<<locn<<"\n";
	locn = MIN(locn, 1000);
    for(int i = 1; i <= locn; i++){
        fout<<loc[i]<<" ";
    }
}

void preproces(){
    v[0] = 0;
    for(int i = 1, j = 0, n = strlen(pat); i < n; i ++){
        while(j && pat[i] != pat[j]){
            j = v[j - 1];
        }
        if(pat[i] == pat[j]){
            ++ j;
        }
        v[i] = j;
    }
    return;
}

void kmp(){
    for(int i = 0, j = 0, n = strlen(txt), maxim = strlen(pat) ; i < n; i ++){
        while(j && txt[i] != pat[j]){
            j = v[j - 1];
        }
        if(txt[i] == pat[j]){
            ++ j;
            if(j == maxim){
                ++ locn;
                j = v[j - 1];
                if(locn <= 1000){
                    loc[locn] = i - maxim + 1;
                }
            }
        }
    }
    return;
}

int main(){
	fin>>pat>>txt;
	preproces();
	kmp();
	print();
	return 0;
}
