#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>

#define nMax 100003
#define expr (buffer + i_expr)

using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

int i_expr = 0;
char buffer[nMax];

int eval_expresion(){
    int number = 0;
    queue < int > terms;
    queue < char > op;
    while(*expr != ')'){
        if(('0' <= *expr) && (*expr <= '9')){
            number = number * 10 + (*expr - '0');
        }
        else if(*expr == '('){
            i_expr++;
            number = eval_expresion();
        }
        else{
            terms.push(number);
            op.push(*expr);
            number = 0;
        }
        i_expr++;
    }
    terms.push(number);
    int t1, t2;
    char op1;
    t1 = terms.front();
    terms.pop();
    while(!terms.empty()){
        op1 = op.front();
        op.pop();
        t2 = terms.front();
        terms.pop();
        if(op1 == '-' || op1 == '+'){
            if((op.front() == '/' || op.front() == '*') && !op.empty()){ //&& !op.empty()
                if(op1 == '-'){
                    t2 *= -1;
                }
                terms.push(t1);
                op.push('+');
                t1 = t2;
                continue;
            }
            switch(op1){
            case '+':
                t1 += t2;
                break;
            case '-':
                t1 -= t2;
                break;
            }
        }
        else{
            switch(op1){
            case '*':
                t1 *= t2;
                break;
            case '/':
                t1 /= t2;
                break;
            }
        }
    }
    return t1;
}


int main(){
	fin>>buffer;
	buffer[strlen(buffer)] = ')';
	fout<<eval_expresion();
	return 0;
}
