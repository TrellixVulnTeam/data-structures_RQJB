#ifndef HEAPS_MINHEAP_H
#define HEAPS_MINHEAP_H


class MinHeap {
private:
    int *arr;
    int size;
public:
    explicit MinHeap();
    static int parent(int i);
    static int left(int i);
    static int right(int i);
    void MinHeapify(int i);
    int getMin();
    int popMin();
    void decreaseKey(int i, int key);
    void insert(int key);
    int * heapSort();
    void display();
    static void swap(int *x, int *y);
};

#endif //HEAPS_MINHEAP_H
