#include "skiplist.h"

int main(int argc, char const *argv[]) {
    ifstream fin("data.in");
    ifstream fout("data.out");
    srand(time(NULL));

    skipList<float> lst(10);
    lst.displayList();



    lst.insert(3);
    lst.insert(2.7);
    lst.insert(2);
    lst.insert(2);
    lst.insert(2);
    lst.insert(2);
    lst.insert(2);
    lst.insert(2.8);
    lst.insert(2);
    lst.insert(2);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3.3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(3);
    lst.insert(2);
    lst.displayList();
    lst.remove(2.7);
    lst.search(2.7);
    lst.search(2.8);
    lst.displayList();





    fout.close();
    fin.close();
    return 0;
}
