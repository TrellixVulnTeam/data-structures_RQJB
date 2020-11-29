#include <iostream>
#include <vector>

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
        return;
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
        return;
    }
};

void test1(){ // Standart ekleme ve silme işlemleri
    clock_t tStart = clock();

    DoublyLinkedList test;

    for(int i=0; i<=100000000; i++)
        test.insert(i);

    clock_t insertionTime = clock();
    clock_t t1 = insertionTime-tStart;

    for(int i=0; i<=100000000; i++)
        test.deleteNode(i);

    clock_t deleteTime = clock();
    clock_t t2 = deleteTime-insertionTime;
    printf("Time taken: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    printf("Insertion Time: %.4fs\n", (double) t1 / CLOCKS_PER_SEC);
    printf("Delete Time: %.4fs\n", (double) t2 / CLOCKS_PER_SEC);
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