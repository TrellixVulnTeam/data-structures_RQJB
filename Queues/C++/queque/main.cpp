#include <iostream>

using namespace std;

class Queue{
private:
    struct node{
        int value;
        node *next;

        node();
        node(int &value) :value{value}{}
        ~node();
    };
    node *head, *tail;
public:
    Queue(){
        head= nullptr;
        tail= nullptr;
    }
    ~Queue(){}

    void enque(int value){
        if(head== nullptr){
            head=new node(value);
            tail=head;
        }else{
            tail->next=new node(value);
            tail=tail->next;
        }
    }

    void deque(){
        if(head== nullptr)
            cout<<"Empty queue"<<endl;
        else if(head->next!= nullptr)
            head=head->next;
        else
            head= nullptr;
    }

    void display(){
        if(head== nullptr) {
            cout << "Empty queue" << endl;
            return;
        }
        node *it=head;

        while(it!= nullptr){
            cout<<it->value<<"->";
            it=it->next;
        }
        cout<<endl;
    }

    bool isEmpty(){
        return head==nullptr;
    }

};

void test1(){
    Queue queue;
    for(int i=0; i<10; i++){
        queue.enque(i);
        queue.display();
    }
    cout<<queue.isEmpty()<<endl;

    for(int i=0; i<10; i++){
        queue.deque();
        queue.display();
    }

    queue.deque();
    cout<<queue.isEmpty()<<endl;
}
void test2(){
    Queue queue;
    clock_t tStart = clock();

    for(int i=0; i<10000000; i++)
        queue.enque(i);

    clock_t insertionTime = clock();
    clock_t t1 = insertionTime-tStart;

    for(int i=0; i<10000000; i++)
        queue.deque();

    clock_t deleteTime = clock();
    clock_t t2 = deleteTime-insertionTime;

    printf("Time taken: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    printf("Insertion Time: %.4fs\n", (double) t1 / CLOCKS_PER_SEC);
    printf("Delete Time: %.4fs\n", (double) t2 / CLOCKS_PER_SEC);
}
int main() {
    //test1();
    test2();
    return 0;
}
