#include <iostream>
#include "hashtable.h"







int main(int argc, char const *argv[]) {
  hashTable<string, int> h(103, hashString);
  h.put("aaa");
  h.put("bbb");
  h.put("ccc");
  h.remove("ccc");
  cout<<"\n"<<h.get("bbb");
  cout<<"\n"<<h.get("ccc");
  return 0;
}
