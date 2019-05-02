#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("trie.in");
ofstream fout("trie.out");

class trie{
public:
    int times = 0, ways = 0;
    trie *v[26] = {};
    void insert(char cuv[20]);
    bool remove(char cuv[20]);
    int nr_world(char cuv[20]);
    int lprefix(char cuv[20]);
}*root;

void trie :: insert(char cuv[20]){
    if(!cuv[0]){
        ++ times;
        return;
    }
    int i = cuv[0] - 'a';
    if(v[i] == NULL){
        v[i] = new trie;
         ++ ways;
    }
    v[i] ->insert(cuv + 1);
    return;
}

bool trie :: remove(char cuv[20]){
    if(!cuv[0]){
        if(times){
            -- times;
        }
        if((!times) && (!ways)){
            return 1;
        }
        return 0;
    }
    int i = cuv[0] - 'a';
    if(v[i] == NULL){
        return 0;
    }
    if(v[i] ->remove(cuv + 1)){
        delete v[i];
        v[i] = NULL;
        -- ways;
        if((!times) && (!ways)){
            return 1;
        }
    }
    return 0;
}

int trie :: nr_world(char cuv[20]){
    if(!cuv[0]){
        return times;
    }
    int i = cuv[0] -'a';
    if(!v[i]){
        return 0;
    }
    return v[i] ->nr_world(cuv + 1);
}

int trie :: lprefix(char cuv[20]){
    if(!cuv[0]){
        return 0;
    }
    int i = cuv[0] - 'a';
    if(!v[i]){
        return 0;
    }
    return (1 + v[i] ->lprefix(cuv + 1 ));
}

int main(){
    int var;
    char cuv[20];
    root = new trie;
	while(true){
        fin>>var>>cuv;
        if(fin.eof()){
            break;
        }
        switch(var){
        case 0:
            root ->insert(cuv);
            break;
        case 1:
            root ->remove(cuv);
            break;
        case 2:
            fout<<root ->nr_world(cuv)<<"\n";
            break;
        default:
            fout<<root ->lprefix(cuv)<<"\n";
            break;
            }
	}
	return 0;
}
