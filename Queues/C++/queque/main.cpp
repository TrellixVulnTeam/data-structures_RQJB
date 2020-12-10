#include <iostream>
#include <chrono>

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
    auto begin = chrono::high_resolution_clock::now();

    for(int i=0; i<100000000; i++)
        queue.enque(i);

    auto t1 = chrono::high_resolution_clock::now();
    auto insertion = chrono::duration_cast<chrono::nanoseconds>(t1-begin);

    for(int i=0; i<100000000; i++)
        queue.deque();

    auto t2 = chrono::high_resolution_clock::now();
    auto deletion = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(t2-begin);

    printf("Time Taken: %.4f s \n", elapsed.count()*1e-9 );
    printf("Insertion Time: %.4f s \n", insertion.count()*1e-9 );
    printf("Deletion Time: %.4f s \n", deletion.count()*1e-9);
}
int main() {
    //test1();
    test2();
    return 0;
}
