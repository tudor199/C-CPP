#include <iostream>
#include <vector>

#define INF 1000
#define MIN(a, b) ( a < b ? a : b)
#define MAX(a, b) ( a > b ? a : b)

using namespace std;

class node{
public:
    vector< node* > son;
    int val;
    int m[3][3]{};
    node(int val_) : val(val_) {}
    void inorder(node *now);
    int minmaxab(node *now, int alpha, int beta);
} *root = new node(-INF);

void node::inorder(node *now){
    cout<<now->val<<" ";
    for(int i = 0; i < now->son.size(); i ++){
        inorder(now->son[i]);
    }
    return;
}

int node::minmaxab(node *now, int alpha, int beta){
    if(now->val != -INF && now->val != INF){ // Leaf
        cout<<"now->val; "<<now->val<<"\n";
        return now->val;
    }
    int c_val;
    if(now->val == -INF){ // Get max
        int maxim = -INF;
        for(int i = 0; i < now->son.size(); i ++){
            c_val = minmaxab(now->son[i], alpha, beta);
            maxim = max(c_val, maxim);
            alpha = max(maxim, alpha);
            if(beta <= alpha){
                break;
            }
        }
        cout<<"maxim: "<<maxim<<"\n";
        return maxim;
    }
    if(now->val == INF){ // Get min
        int minim = INF;
        for(int i = 0; i < now->son.size(); i ++){
            c_val = minmaxab(now->son[i], alpha, beta);
            minim = min(c_val, minim);
            beta = min(minim, beta);
            if(beta <= alpha){
                break;
            }
        }
        cout<<"minim: "<<minim<<"\n";
        return minim;
    }
    return 0;
}





int minmax(node *now){
    if(now->val != -INF && now->val != INF){ // Leaf
        cout<<"now->val; "<<now->val<<"\n";
        return now->val;
    }
    int c_val;
    if(now->val == -INF){ // Get max
        int maxim = -INF;
        for(int i = 0; i < now->son.size(); i ++){
            c_val = minmax(now->son[i]);
            maxim = max(c_val, maxim);
        }
        cout<<"maxim: "<<maxim<<"\n";
        return maxim;
    }
    if(now->val == INF){ // Get min
        int minim = INF;
        for(int i = 0; i < now->son.size(); i ++){
            c_val = minmax(now->son[i]);
            minim = min(c_val, minim);
        }
        cout<<"minim: "<<minim<<"\n";
        return minim;
    }
}

int main()
{
    node *a, *b, *c;
    a = new node(INF);
    a->son.push_back(new node(4));
    a->son.push_back(new node(5));
    root->son.push_back(a);

    a = new node(INF);
    b = new node(-INF);
    b->son.push_back(new node(3));
    b->son.push_back(new node(4));
    c = new node(-INF);
    c->son.push_back(new node(7));
    c->son.push_back(new node(9));
    a->son.push_back(new node(6));
    a->son.push_back(b);
    a->son.push_back(c);
    root->son.push_back(a);

    a = new node(INF);
    a->son.push_back(new node(3));
    a->son.push_back(new node(8));
    root->son.push_back(a);


    root->inorder(root);
    cout<<"\n\n\n";
    cout<<minmax(root);
    cout<<"\n\n\n";
    cout<<root->minmaxab(root, -INF, INF);
    return 0;
}
