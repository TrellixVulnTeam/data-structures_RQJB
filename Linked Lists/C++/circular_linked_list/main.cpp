#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class CircularLinkedList{
private:
    struct node{
        int value;
        node *next;

        node(){}
        node(int &value) :value{value}{}
        ~node(){}
    };

    node *head,*current;
public:
    CircularLinkedList(){
        head= nullptr;
        current= nullptr;
    }
    ~CircularLinkedList(){}

    void display(){
        node *it=head;

        cout<<it->value<<" ";
        it=it->next;

        while (it!=head){
            cout<<it->value<<" ";
            it=it->next;
        }

        cout<<endl;
    }

    void insert(int value){
        if(head== nullptr){
            head=new node(value);
            current=head;
            head->next=head;
            return;
        }else{
            current->next=new node(value);
            current=current->next;
            current->next=head;
        }
    }

    void insertInOrder(int value){
        if(head==nullptr){
            head = new node(value);
            current=head;
            head->next=head;
            return;
        }

        if(head->value > value){
            node *temp=new node(head->value);

            temp->next=head->next;
            head->next=temp;
            head->value=value;
            return;
        }

        node *it=head;
        while(it->next!=head && it->next->value < value){
            it=it->next;
        }
        node *temp=new node();
        temp->next=it->next;
        it->next=temp;
        temp->value=value;
   }

    void deleteNode(int value){
        if(head== nullptr)
            return;

        if(head->next==head && head->value==value){
            free(head);
            return;
        }


        node *it=head;
        node *temp;

        if(head->value == value){
            while(it->next!=head)
                it=it->next;

            it->next=head->next;
            head=head->next;
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

    CircularLinkedList test;

    for(int i=1; i<=100000; i++)
        test.insert(i);

    auto t1 = chrono::high_resolution_clock::now();
    auto insertion = chrono::duration_cast<chrono::nanoseconds>(t1-begin);

    for(int i=1; i<=100000; i++)
        test.deleteNode(i);

    auto t2 = chrono::high_resolution_clock::now();
    auto deletion = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(t2-begin);

    printf("Time Taken: %.4f s \n", elapsed.count()*1e-9 );
    printf("Insertion Time: %.4f s \n", insertion.count()*1e-9 );
    printf("Deletion Time: %.4f s \n", deletion.count()*1e-9);
}
void test2(){ //Sıralı ekleme
    CircularLinkedList test;
    vector<int> vec{3,5,4,9,12,2,10,1,-5,13,7};

    for(int num:vec)
        test.insertInOrder(num);

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
