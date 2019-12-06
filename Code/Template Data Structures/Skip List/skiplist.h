#ifndef __SKIPLIST_H
#define __SKIPLIST_H

#include <iostream>
#include <fstream>
#include <cstring>


#include <ctime>
#include <cstdlib>
#include <cmath>

#define INF 2000000000

using namespace std;

template<typename T>
class skipList {
  private:
    struct node {
      T data;
      node **next, **prev;

      node(T, int);
      ~node();
    };

    int maxLvl, level;
    node *head, *tail;
  public:
    skipList(int);
    ~skipList();
    int getRandLevel(int);
    void insert(T);
    void search(T);
    void remove(T);
    void displayList();
};

#endif
