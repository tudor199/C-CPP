#include "header.h"

template<typename T>
void Tswap(T& a, T& b) {
  T aux = a;

  a = b;
  b = aux;
}

template<typename T>
MinHeap<T>::MinHeap(int cap) {
  size     = 0;
  capacity = cap;
  arr      = new T[cap];
}

template<typename T>
MinHeap<T>::~MinHeap() {
  delete arr;
}

template<typename T>
int MinHeap<T>::parent(int i) {
  return (i - 1) / 2;
}

template<typename T>
int MinHeap<T>::left(int i) {
  return 2 * i + 1;
}

template<typename T>
int MinHeap<T>::right(int i) {
  return 2 * i + 2;
}

template<typename T>
T MinHeap<T>::getMin() {
  return this->arr[0];
}

template<typename T>
T MinHeap<T>::getSize() {
  return this->size;
}

template<typename T>
T MinHeap<T>::getCapacity() {
  return this->capacity;
}

template<typename T>
bool MinHeap<T>::empty() {
  return this->size == 0;
}

template<typename T>
void MinHeap<T>::resize(int newCap) {
  T *tempArr = new T[newCap];

  if (this->capacity < newCap) {
    for (size_t i = 0; i < this->capacity; i++) {
      tempArr[i] = this->arr[i];
    }
  }

  if (this->capacity > newCap) {
    for (size_t i = 0; i < newCap; i++) {
      tempArr[i] = this->arr[i];
    }

    if (newCap < this->size) {
      this->size = newCap;
    }
  }

  this->capacity = newCap;
  delete this->arr;
  this->arr = tempArr;
}

template<typename T>
T MinHeap<T>::extractMin() {
  if (this->size == 0) {
    cout << "Heap is empty\n";
    return -1;
  }

  T return_value = this->arr[0];
  this->arr[0] = this->arr[this->size - 1];
  --this->size;
  pushDown(0);
  return return_value;
}

template<typename T>
void MinHeap<T>::insertKey(T data) {
  if (this->capacity == this->size) {
    this->resize(this->capacity + 10);
  }
  this->arr[this->size] = data;
  ++this->size;
  pushUp(this->size - 1);
}

template<typename T >
void MinHeap<T>::pushUp(int idx) {
  if(idx == 0) {
    return;
  }
  while (this->arr[parent(idx)] > this->arr[idx]) {
    swap(this->arr[parent(idx)], this->arr[idx]);
    idx = parent(idx);
  }
}

template<typename T >
void MinHeap<T>::pushDown(int idx) {
  if(idx >= this->size) {
    return;
  }
  while (true) {
    int lidx = left(idx),
        ridx = right(idx);
    if (lidx >= this->size || ridx >= this->size) {
      break;
    }
    if (this->arr[lidx] >= this->arr[idx] && this->arr[ridx] >= this->arr[idx]) {
      break;
    }

    if (this->arr[lidx] < this->arr[ridx]) {
      swap(this->arr[lidx], this->arr[idx]);
      idx = lidx;
    } else {
      swap(this->arr[ridx], this->arr[idx]);
      idx = ridx;
    }
  }
}

template class MinHeap<int>;
template class MinHeap<float>;
