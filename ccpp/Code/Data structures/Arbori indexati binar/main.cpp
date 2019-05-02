#include <iostream>
#include <fstream>

#define nMax 100003

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

class BITree{
public:
    int v[nMax] = {};
    int n;
    void update(int index, int val);
    int get_sum(int index);
    int get_sum_range(int x, int y);
    int binary_search(int val);
    BITree(int i_v[100], int el){
        n = el;
        for(int i = 1; i <= n; i ++){
            update(i, i_v[i]);
        }
    }
};

void BITree :: update(int index, int val){
    while(index <= n){
        v[index] += val;
        index += index & -index;
    }
    return;
}

int BITree :: get_sum(int index){
    int sum = 0;
    while(index > 0){
        sum += v[index];
        index -= index & -index;
    }
    return sum;
}

int BITree :: get_sum_range(int x, int y){
    int aaa = get_sum(x - 1);
    int bbb = get_sum(y);
    return (bbb - aaa);
}

int BITree :: binary_search(int val){
    int csum, lo = 1, hi = n, mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        csum = get_sum(mid);
        if(csum == val){
            return mid;
        }
        else{
            if(val < csum){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    int n, v[nMax] = {}, querries, q, a, b;
    fin>>n>>querries;;
    for(int i = 1; i <= n; i++)
        fin>>v[i];
    BITree tree(v,n);
    while(querries--){
        fin>>q;
        if(q == 0){
            fin>>a>>b;
            tree.update(a, b);
        }
        else{
            if(q == 1){
                fin>>a>>b;
                fout<<tree.get_sum_range(a, b)<<"\n";
            }
            else{
                fin>>a;
                fout<<tree.binary_search(a)<<"\n";
            }
        }
    }

	return 0;
}
