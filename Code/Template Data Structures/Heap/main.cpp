#include "header.h"

int main()
{
    MinHeap<float> h(2);
    cout<<"h.parrent(3) = "<<h.parent(3)<<"\n";
    cout<<"h.left(3) = "<<h.left(3)<<"\n";
    cout<<"h.right(3) = "<<h.right(3)<<"\n";
    h.insertKey(3.1);
    cout<<h.getMin()<<"\n";
    h.insertKey(2.2);
    cout<<h.getMin()<<"\n";
    h.insertKey(1);
    cout<<h.getMin()<<"\n";
    h.insertKey(4.7);
    cout<<h.getMin()<<"\n";
    cout<<"h.getSize() = "<<h.getSize()<<"\n";
    cout<<"h.getCapacity() = "<<h.getCapacity()<<"\n";
    cout<<"heap in order:\n";
    while (!h.empty()) {
      cout<<h.extractMin()<<"\n";
    }
    cout<<h.extractMin()<<"\n";
    return 0;
}
