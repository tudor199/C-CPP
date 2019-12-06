#include <iostream>

#define nMax 103

using namespace std;

int n,sti;
int stiva[nMax];

bool bun(){
    for(int i=1;i<n/2;i++){
        if(stiva[i]>=stiva[i+1]){
            return false;
        }
        if(stiva[i]>=stiva[i+n/2]){
            return false;
        }
    }
    if(stiva[n/2]>=stiva[n]){
        return false;
    }
    for(int i=n/2+1;i<n;i++){
        if(stiva[i]>=stiva[i+1]){
            return false;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(stiva[i]==stiva[j]){
                return false;
            }
        }
        for(int j=i+1;j<=n;j++){
            if(stiva[i]==stiva[j]){
                return false;
            }
        }
    }
    return true;
}

void bk(int k){
    if(k==n+1){
        if(bun()){
            for(int i=1;i<=n/2;i++){
                cout<<stiva[i]<<" ";
            }
            cout<<"   ";
            for(int i=n/2+1;i<=n;i++){
                cout<<stiva[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    for(int i=1;i<=n;i++){
        stiva[k]=i;
        bk(k+1);
    }
}

int main()
{
    cin>>n;
    n*=2;
    bk(1);
    return 0;
}
