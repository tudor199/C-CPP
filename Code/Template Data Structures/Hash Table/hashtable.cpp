#include "hashtable.h"

using namespace std;

int hashString(string A, int mod) {
  int sum = 0;
  for (size_t i = 0; i < A.length(); i++) {
    sum = (sum + A[i] * (i + 1)) % mod;
  }
  return sum;
}

template <typename Tkey, typename Tval>
hashTable<Tkey, Tval>::hashTable(int mod, int (*h)(Tkey, int)) {
  size = 0;
  this->mod = mod;
  H = new std::list<data> [mod];
  hashFunction = h;
}
template <typename Tkey, typename Tval>
hashTable<Tkey, Tval>::~hashTable() {
  delete[] H;
}

template <typename Tkey, typename Tval>
void hashTable<Tkey, Tval>::put(Tkey key) {
  int idx = hashFunction(key, mod);
  data data;
  data.key = key;
  data.value = size;
  H[idx].push_back(data);
  ++size;
  return;
}

template <typename Tkey, typename Tval>
void hashTable<Tkey, Tval>::remove(Tkey key) {
  int idx = hashFunction(key, mod);
  for (auto it = H[idx].begin(); it != H[idx].end(); ++it){
    if(it->key == key) {
      H[idx].erase(it);
      --size;
      return;
    }
  }
  return;
}

template <typename Tkey, typename Tval>
Tval hashTable<Tkey, Tval>::get(Tkey key) {
  int idx = hashFunction(key, mod);
  for (auto it = H[idx].begin(); it != H[idx].end(); ++it){
    if(it->key == key) {
      return it->value;
    }
  }
  return Tval();
}

template class hashTable<int, int>;
template class hashTable<string, int>;
