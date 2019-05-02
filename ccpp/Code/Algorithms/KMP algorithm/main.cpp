#include <iostream>
#include <cstring>
#include <fstream>

#define nMax 103

using namespace std;

ifstream fin("file.in");

int v[nMax];
char pat[nMax], txt[nMax];

void preprocess(){
    v[0] = 0;
    for(int i = 1, j = 0, n = strlen(pat); i < n; i ++){
        while(pat[i] != pat[j] && j != 0){
            j = v[ j - 1];
        }
        if(pat[i] == pat[j]){
            ++ j;
            v[i] = j;
        }
        else{
            v[i] = 0;
        }
    }
    return;
}

void KMP(){
    for(int i = 0, j = 0, n = strlen(txt), m = strlen(pat); i < n; i ++){
        if(txt[i] == pat[j]){
            if(j == m - 1){
                cout<<i - j<<"\n";
                j = v[j];
            }
            else{
                ++ j;
            }
        }
        else{
            j = v[j];
        }
    }
}

int main(){
    fin>>txt>>pat;
    preprocess();
    for(int i = 0; pat[i]; i ++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n\n";
    KMP();
	return 0;
}
