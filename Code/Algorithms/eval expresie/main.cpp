#include <iostream>
#include <fstream>

using namespace std;
ifstream f("evaluare.in");
ofstream g("evaluare.out");
int suma(),produs(),factor(),numar();
char e[100010],*c;
int main()
{
    f>>e;
    c=e;
    cout<<suma();
    return 0;
}
int suma()
{
    int rez=produs();
    while(*c=='+'||*c=='-')
    {
        if(*c=='+'){c++;rez+=produs();}
        else {c++;rez-=produs();}
    }
    return rez;
}
int produs()
{
    int rez=factor();
    while(*c=='*'||*c=='/')
    {
        if(*c=='*'){c++;rez*=factor();}
        else {c++;rez/=factor();}
    }
    return rez;
}
int factor()
{
    int rez;
    if(*c=='(')
    {
        c++;rez=suma();c++;return rez;
    }
    return numar();
}
int numar()
{
    int rez=0;
    while(isdigit(*c))
    {
        rez=10*rez+*c-'0';
        c++;
    }
    return rez;
}
