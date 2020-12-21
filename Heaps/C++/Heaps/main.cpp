#include <iostream>
#include <queue>
#include "MaxHeap.h"
#include "MaxHeap.cpp"
#include "MinHeap.h"
#include "MinHeap.cpp"

using namespace std;

void test1(){
    MaxHeap heap(9);
    vector<int> vec{7,6,8,5,9,4,10,2,3};

    for(int &key:vec)
        heap.insert(key);

    cout<<heap.getMax()<<endl;
    heap.display();

    int *sortedHeap = heap.heapSort();

    for(int i=0; i<9; i++)
        cout<<sortedHeap[i]<<"-";
}

void test2(){
    MaxHeap heap(5);
    vector<int> vec{10,3,7,1,4};

    for(int &key:vec)
        heap.insert(key);

    heap.display();
    heap.popMax();
    heap.display();
    heap.insert(20);
    heap.display();
    heap.popMax();
    heap.display();
}

void test3(){
    MinHeap heap(9);
    vector<int> vec{7,6,8,5,9,4,10,2,3,1,20};

    for(int &key:vec)
        heap.insert(key);

    heap.display();
}

void MaxHeapImplementedWithPriorityQueue(){
    priority_queue<int> pq;

    vector<int> vec{7,6,8,5,9,4,10,2,3};

    for(int &key:vec)
        pq.push(key);

    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
void MinHeapImplementedWithPriorityQueue(){
    priority_queue<int, vector<int>, greater<>> pq;

    vector<int> vec{7,6,8,5,9,4,10,2,3};

    for(int &key:vec)
        pq.push(key);

    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
void display(const vector<int>& vec){
    for(int num: vec)
        cout<<num<<" ";
    cout<<endl;
}
void HeapInSTL(){
    vector<int> vec{7,6,8,5,9,4,10,2,3};
    //Max Heap
    make_heap(vec.begin(), vec.end());  //Vektörü heap haline getirir
    cout<<"Heap:";
    display(vec);
    cout<<"Max: "<<vec.front()<<endl;

    vec.push_back(30);
    push_heap(vec.begin(), vec.end());  //Vektöre yeni elemean eklenmesi durumda yeniden düzenlemek için kullanılır
    cout<<"Push heap:";
    display(vec);
    cout<<"Max: "<<vec.front()<<endl;

    pop_heap(vec.begin(), vec.end()); //Maksimum değerli elemanı silmek için kullanılır
    vec.pop_back();
    cout<<"Pop heap:";
    display(vec);
    cout<<"Max: "<<vec.front()<<endl;

    sort_heap(vec.begin(), vec.end());
    cout<<"Sort heap:";
    display(vec);

    cout<<"Is Heap:"<<is_heap(vec.begin(), vec.end())<<endl;
    make_heap(vec.begin(), vec.end());
    cout<<"Is Heap:"<<is_heap(vec.begin(), vec.end())<<endl;

    auto it = is_heap_until(vec.begin(), vec.end());
    cout<<"Heap:";
    for (auto i = vec.begin(); i!=it; i++)
        cout<<*i<<" ";
}
int main() {
    //test1();
    //test2();
    //test3();
    //MaxHeapImplementedWithPriorityQueue();
    //MinHeapImplementedWithPriorityQueue();
    HeapInSTL();
    return 0;
}
