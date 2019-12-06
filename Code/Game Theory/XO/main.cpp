#include <iostream>
#include <vector>

#define INF 1000

#define MIN(a, b) ( a < b ? a : b)
#define MAX(a, b) ( a > b ? a : b)

#define BEST_MOVE_RECORD xb = i, yb = j;

using namespace std;


class node{
public:
    int val;
    int xb, yb;
    int m[3][3] = {};
    node(int val_) : val(val_) {}
    node(int val_, int m_[3][3], int i_, int j_){
        val = val_;
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                m[i][j] = m_[i][j];
            }
        }
        m[i_][j_] = (val == INF ? 1 : -1);
        val = set_value();
    }
    node(int val_, int m_[3][3]){
        val = val_;
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                m[i][j] = m_[i][j];
            }
        }
        val = set_value();
    }
    void show_m();
    int minmaxab(int alpha, int beta);
    int set_value();
} *root;

void node::show_m(){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            cout<<(m[i][j] == 0 ? "+" : (m[i][j] == 1 ? "X" : "O"));
        }
        cout<<"\n";
    }
    return;
}

int node::set_value(){
    for(int i = 0; i < 3; i ++){
        if(m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][1] != 0){
            return m[i][1];
        }
    }
    for(int j = 0; j < 3; j ++){
        if(m[0][j] == m[1][j] && m[1][j] == m[2][j] && m[1][j] != 0){
            return m[1][j];
        }
    }
    if(m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[1][1] != 0){
        return m[1][1];
    }
    if(m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[1][1] != 0){
        return m[1][1];
    }
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            if(m[i][j] == 0){
                return val;
            }
        }
    }
    return 0;
}

int node::minmaxab(int alpha, int beta){
    if(val != -INF && val != INF){ // Leaf
        return val;
    }
    int c_val;
    node *a;
    if(val == -INF){ // Get max
        int maxim = -INF;
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                if(m[i][j] == 0){
                    a = new node(INF, m, i, j);
                    c_val = a->minmaxab(alpha, beta);
                    maxim = max(c_val, maxim);
                    if(alpha < maxim){
                        BEST_MOVE_RECORD
                    }
                    alpha = max(maxim, alpha);
                    delete a;
                    if(beta <= alpha){
                        return maxim;
                    }
                }
            }
        }
        return maxim;
    }
    if(val == INF){ // Get min
        int minim = INF;
        for(int i = 0; i < 3; i ++){
            for(int j = 0; j < 3; j ++){
                if(m[i][j] == 0){
                    a = new node(-INF, m, i, j);
                    c_val = a->minmaxab(alpha, beta);
                    minim = min(c_val, minim);
                    if(beta > minim){
                        BEST_MOVE_RECORD
                    }
                    beta = min(minim, beta);
                    delete a;
                    if(beta <= alpha){
                       return minim;
                    }
                }
            }
        }
        return minim;
    }
    return 0;
}

int main()
{
    int x, y;
    int ttt[3][3] = {};
    root = new node(-INF);
    cout<<"----------------------------------------------------\n";
    for(int i = 1; i <= 9; i ++){
        root->show_m();
        cout<<"\n"<<(i % 2 == 1 ? "X" : "O")<<" turn: \n";
        cout<<"\nState: "<<root->minmaxab(-INF, INF);
        cout<<"\nBest move: "<<root->xb<<" "<<root->yb<<"\n\n";
        cin>>x>>y;
        if(ttt[x][y] != 0){
            -- i;
            continue;
        }
        if(i % 2 == 1){ // X turn
            ttt[x][y] = 1;
            root = new node(INF, ttt);
            if(root->val == 1){
                cout<<"\n\n\nX wins:\n";
                root->show_m();
                return 0;
            }
            else if(root->val == 0){
                cout<<"\n\n\nDraw:\n";
                root->show_m();
                return 0;
            }
        }
        else{ // O turn
            ttt[x][y] = -1;
            root = new node(-INF, ttt);
            if(root->val == -1){
                cout<<"\n\n\nO wins:\n";
                root->show_m();
                return 0;
            }
            else if(root->val == 0){
                cout<<"\n\n\nDraw:\n";
                root->show_m();
                return 0;
            }
        }
        root->show_m();
        cout<<"----------------------------------------------------\n";
    }
    cout<<root->minmaxab(-INF, INF);
    return 0;
}
