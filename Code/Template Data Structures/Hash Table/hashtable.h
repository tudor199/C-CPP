#ifndef __HASHTABLE_H_
#define __HASHTABLE_H_

#include <iostream>
#include <list>
#include <string>

using namespace std;

int hashString(string A, int mod) ;

template <typename Tkey, typename Tval>
class hashTable {
private:
  struct data {
    Tkey key;
    Tval value;
  };
  int size, mod;
  std::list< data > *H;
  int (*hashFunction)(Tkey, int);

public:
  hashTable(int, int (*h)(Tkey, int));
  ~hashTable();
  void put(Tkey);
  void remove(Tkey);
  Tval get(Tkey);
};
#endif
