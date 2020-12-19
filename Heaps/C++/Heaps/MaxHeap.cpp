#include "MaxHeap.h"
#include <iostream>
#include <climits>

using namespace std;

MaxHeap::MaxHeap(int capacity) :size{0}{
    arr = new int[capacity];
}

int MaxHeap::parent(int i) {
    return (i-1)/2;
}

int MaxHeap::left(int i) {
    return (2*i+1);
}

int MaxHeap::right(int i) {
    return (2*i+2);
}

void MaxHeap::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MaxHeap::MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest{i};

    if(l<=size && arr[l]>arr[i])
        largest = l;

    if (r<=size && arr[r]>arr[largest])
        largest = r;

    if (largest != i){
        swap(&arr[i], &arr[largest]);
        MaxHeapify(largest);
    }
}

int MaxHeap::getMax() {
    return arr[0];
}

int MaxHeap::popMax() { // O(log n)
    if (size<=0){
        cout<<"Heap underflow"<<endl;
        return 1;
    }
    if (size == 1){
        size--;
        return arr[0];
    }

    int max = arr[0];
    arr[0] = arr[size-1];
    size--;
    MaxHeapify(0);
    return max;
}

void MaxHeap::increaseKey(int i, int key) { // O(log n)
    if (key<arr[i]){
        cout<<"New key is smaller than current key"<<endl;
        return;
    }

    arr[i] = key;
    while (i>0 && arr[parent(i)]<arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::insert(int key){ // O(log n)
    size++;
    arr[size-1] = INT_MIN;
    increaseKey(size-1, key);
}

int * MaxHeap::heapSort() { // o(log n)
    int *sortedHeap = new int[size];

    for (int i=size-1; i>=0; i--){
        sortedHeap[i] = popMax();
    }

    return sortedHeap;
}

void MaxHeap::display() {
    for(int i=0; i<size; i++)
        cout<<arr[i]<<"-";
    cout<<endl;
}


