#include <iostream>
#include <chrono>

using namespace std;

class Stack{
private:
    struct node{
        int value;
        node *prev;

        node();
        node(int &value) :value{value}{}
        ~node();
    };
    node *topNode;
    int size{0};
public:

    Stack(){
        topNode= nullptr;
    }
    ~Stack(){}

    void push(int value){
        node *temp = new node(value);
        temp->prev=topNode;
        topNode=temp;
        size++;
    }

    void pop(){
        node *temp;
        if(topNode== nullptr){
            cout<<"Empty Stack"<<endl;
            return;
        } else{
            temp=topNode;
            topNode=topNode->prev;
            temp->prev= nullptr;
            free(temp);
            size--;
        }
    }

    node *top(){
        if(!empty())
            return topNode;
        else
            exit(1);
    }

    bool empty(){
        return topNode == nullptr;
    }

    int getSize(){
        return size;
    }

    void display(){
        node *temp;
        if(topNode == nullptr){
            cout<<"Empty Stack"<<endl;
            return;
        }else{
            temp=topNode;
            while(temp != nullptr){
                cout<<temp->value<<"->";
                temp=temp->prev;
            }
        }
        cout<<endl;
    }
};
void test1(){
    Stack stack;

    for(int i=0; i<5; i++)
        stack.push(i);

    stack.display();
    cout<<"Size: "<<stack.getSize()<<endl;
    cout<<"Top: "<<stack.top()->value<<endl;

    int size= stack.getSize();
    for(int i=0; i<size; i++){
        stack.pop();
        stack.display();
    }
}
void test2(){
    Stack stack;
    auto begin = chrono::high_resolution_clock::now();

    for(int i=0; i<100000000; i++)
        stack.push(i);

    auto t1 = chrono::high_resolution_clock::now();
    auto insertion = chrono::duration_cast<chrono::nanoseconds>(t1-begin);

    for(int i=0; i<100000000; i++)
        stack.pop();

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
