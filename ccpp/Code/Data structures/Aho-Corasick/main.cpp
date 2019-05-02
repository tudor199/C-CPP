#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

#define nMax 103
#define cuvMax 10003
#define txtMax 1000003

using namespace std;

ifstream fin("ahocorasick.in");
ofstream fout("ahocorasick.out");

int n, ord[nMax] = {};
int cindex;
char txt[txtMax];


vector < char > repetition[nMax];

class ahtree{
public:
    vector < char > index;
    ahtree *v[26] = {};
    ahtree *failure;
    void insert(char cuv[cuvMax]);
}*root;

void ahtree :: insert(char cuv[cuvMax]){
    if(!cuv[0]){
        if(index.size()){
            repetition[index[0]].push_back(cindex);
        }
        else{
            index.push_back(cindex);
        }
        return;
    }
    int i = cuv[0] - 'a';
    if(!v[i]){
        v[i] = new ahtree;
    }
    v[i] ->insert(cuv + 1);
    return;
}



void fix_failure(){
    queue < ahtree* > Q;
    ahtree *now = root, *it;
    root ->failure = nullptr;
    for(int i = 0; i < 26; i ++){
        if(root ->v[i]){
            root ->v[i] ->failure = root;
            Q.push(root ->v[i]);
        }
    }
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        if((now ->failure ->index).size()){
            for(int i = 0; i < (now ->failure ->index).size(); i ++){
                (now -> index).push_back((now ->failure ->index)[i]);
            }
        }
        for(int i = 0; i < 26; i ++){
            if(now ->v[i]){
                for(it = now ->failure; it; it = it ->failure){
                    if(it ->v[i]){
                        break;
                    }
                }
                if(it){
                    now ->v[i] ->failure = it ->v[i];
                }
                else{
                    now ->v[i] ->failure = root;
                }
                Q.push(now ->v[i]);
            }
        }
    }
    return;
}


void search(){
    ahtree *now = root;
    int i = 0, j;
    while(txt[i]){
        j = txt[i] - 'a';
        if(now ->v[j]){
            now = now ->v[j];
            ++ i;
            for(int i = 0; i < (now ->index).size(); i ++){
                ++ ord[(now ->index)[i]];
            }
        }
        else{
            if(now ->failure){
                now = now ->failure;
            }
            else{
                ++ i;
            }
        }
    }
    for(int  i = 1; i <= n; i ++){
        for(int j = 0; j < repetition[i].size(); j ++){
            ord[repetition[i][j]] += ord[i];
        }
    }
    return;
}

int main(){
    char cuv[cuvMax];
    root = new ahtree;
    fin>>txt>>n;
    for(cindex = 1; cindex <= n; cindex ++){
        fin>>cuv;
        root ->insert(cuv);
    }
    fix_failure();
    search();
    for(int i = 1; i <= n; i ++){
        fout<<ord[i]<<"\n";
    }
	return 0;
}
