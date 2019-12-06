#include <iostream>

using namespace std;

int euler(int n){
    int rez = n;
    if(n % 2 == 0){
        do{
            n /= 2;
        }while(n % 2 == 0);
        cout<<rez<<" ";
        rez -= rez / 2;
    }
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            do{
                n /= i;
            }while(n % i == 0);
            rez -= rez / i;
            cout<<rez<<" ";
        }
    }
    if(n > 1){
        rez -= rez / n;
    }
    return rez;
}

int main()
{
    int n;
    cin>>n;
    cout<<euler(n);
    return 0;
}
