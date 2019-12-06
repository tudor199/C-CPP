#ifndef __HEAP_H
#define __HEAP_H

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class MinHeap
{
    T *arr; // Pointer to array of elements in heap
    int capacity; // Maximum size of min heap
    int size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
    ~MinHeap();

    // Returns index of parent of node at index i
    int parent(int);

    // Returns index of left child of node at index i
    int left(int);

    // Returns index of right child of node at index i
    int right(int);

    // Returns the minimum key (key at root) from min heap
    T getMin();

    // Returns the size of the min heap
    T getSize();

    // Returns the capacity of min heap
    T getCapacity();

    // Checks if the min heap is empty
    bool empty();

    // Rezise heap
    void resize(int);
    
    // Returns and extract the minimum key (key at root) from min heap
    T extractMin();

    // Inserts a new key 'k'
    void insertKey(T k);

    void pushUp(int idx);

    void pushDown(int idx);
};

#endif
