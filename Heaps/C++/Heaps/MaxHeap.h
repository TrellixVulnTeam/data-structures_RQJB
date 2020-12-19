#include <vector>

#ifndef HEAPS_MAXHEAP_H
#define HEAPS_MAXHEAP_H


class MaxHeap {
private:
    int *arr;
    int size;
public:
    explicit MaxHeap(int capacity);
    static int parent(int i);
    static int left(int i);
    static int right(int i);
    void MaxHeapify(int i);
    int getMax();
    int popMax();
    void increaseKey(int i, int key);
    void insert(int key);
    int * heapSort();
    void display();
    static void swap(int *x, int *y);
};


#endif //HEAPS_MAXHEAP_H
