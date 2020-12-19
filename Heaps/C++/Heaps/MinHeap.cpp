#include "MinHeap.h"
#include<climits>

MinHeap::MinHeap() :size{0}{
    arr = new int[1];
}

int MinHeap::parent(int i) {
    return (i-1)/2;
}

int MinHeap::left(int i) {
    return (2*i+1);
}

int MinHeap::right(int i) {
    return (2*i+2);
}

void MinHeap::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest{i};

    if (l<=size && arr[l]<arr[i])
        smallest = l;

    if (r<=size && arr[r]<arr[i])
        smallest = r;

    if (smallest != i){
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::getMin() {
    return arr[0];
}

int MinHeap::popMin() {
    if (size<=0){
        cout<<"Heap underflow"<<endl;
        return 1;
    }
    if (size == 1){
        size--;
        return arr[0];
    }

    int min = arr[0];
    arr[0] = arr[size-1];
    size--;
    MinHeapify(0);

    return min;
}

void MinHeap::decreaseKey(int i, int key) {
    if (key>arr[i]){
        cout<<"New key is greater than current key"<<endl;
        return;
    }

    arr[i] = key;
    while (i>0 && arr[parent(i)]>arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::insert(int key) {
    size++;
    arr[size-1] = INT_MAX;
    decreaseKey(size-1, key);
}

int *MinHeap::heapSort() {
    int *sortedHeap = new int[size];

    for (int i=0; i<size; i++){
        sortedHeap[i] = popMin();
    }

    return sortedHeap;
}

void MinHeap::display() {
    for(int i=0; i<size; i++)
        cout<<arr[i]<<"-";
    cout<<endl;
}
