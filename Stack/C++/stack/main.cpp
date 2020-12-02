#include <iostream>

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
    clock_t tStart = clock();

    Stack stack;
    for(int i=0; i<10000000; i++)
        stack.push(i);

    clock_t insertionTime = clock();
    clock_t t1 = insertionTime-tStart;
    int size= stack.getSize();
    for(int i=0; i<size; i++){
        stack.pop();
    }

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
