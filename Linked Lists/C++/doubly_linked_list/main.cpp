#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class DoublyLinkedList{
private:
    struct node{
        int value;
        node *next;
        node *prev;

        node(){}
        node(int &value) :value{value}{}
        ~node(){}
    };

    node *head,*current;
public:
    DoublyLinkedList(){
        head= nullptr;
        current= nullptr;
    }
    ~DoublyLinkedList(){}

    void display(){
        node *it=head;

        while(it != nullptr){
            cout<<it->value<<" ";
            it=it->next;
        }

        cout<<endl;
    }

    void displayReverse(){
        node *it = current;

        while(it != head){
            cout<<it->value<<" ";
            it=it->prev;
        }
        cout<<it->value<<" ";
        cout<<endl;
    }

    void insert(int value){
        if(head == nullptr){
            head=new node(value);
            head->next= nullptr;
            head->prev= nullptr;
            current=head;
            return;
        }else{
            node *temp=current;
            current->next=new node(value);
            current=current->next;
            current->prev=temp;
        }
    }

    void insertInOrder(int value){
        if(head==nullptr){
            head = new node(value);
            head->next= nullptr;
            head->prev= nullptr;
            current=head;
            return;
        }

        if(head->value > value){
            node *temp= new node(head->value);
            temp->next=head->next;
            head->next=temp;
            temp->prev=head;
            head->value=value;
            return;
        }

        node *it=head;
        while(it->next!= nullptr && it->next->value < value){
            it=it->next;
        }

        node *temp=new node();
        temp->next=it->next;
        it->next=temp;
        temp->prev=it;
        if(temp->next!= nullptr)
            temp->next->prev=temp;
        temp->value=value;
   }

    void deleteNode(int value){
        node *it=head;
        node *temp;

        if(head->value == value){
            temp=head;
            head=head->next;
            free(temp);
            return;
        }

        while (it->next!=head && it->next->value!=value){
            it=it->next;
        }

        if(it->next == head){
            cout<<"Value not found"<<endl;
            return;
        }

        temp=it->next;
        it->next=it->next->next;
        free(temp);
   }
};

void test1(){ // Standart ekleme ve silme işlemleri
    auto begin = chrono::high_resolution_clock::now();

    DoublyLinkedList test;

    for(int i=0; i<=100000; i++)
        test.insert(i);

    auto t1 = chrono::high_resolution_clock::now();
    auto insertion = chrono::duration_cast<chrono::nanoseconds>(t1-begin);

    for(int i=0; i<=100000; i++)
        test.deleteNode(i);

    auto t2 = chrono::high_resolution_clock::now();
    auto deletion = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(t2-begin);

    printf("Time Taken: %.4f s \n", elapsed.count()*1e-9 );
    printf("Insertion Time: %.4f s \n", insertion.count()*1e-9 );
    printf("Deletion Time: %.4f s \n", deletion.count()*1e-9);
}
void test2(){ //Sıralı ekleme
    DoublyLinkedList test;
    vector<int> vec{3,5,4,9,12,2,10,1,-5,13,7};

    for(int num:vec)
        test.insertInOrder(num);

    test.display();
    test.deleteNode(-5); //kök silme
    test.deleteNode(13); // son eleman
    test.deleteNode(4); // ara eleman
    test.display();
}

int main() {
    test1();
    //test2();
    return 0;
}