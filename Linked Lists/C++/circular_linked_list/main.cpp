#include <iostream>
#include <vector>

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
        return;
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
        return;
    }
};

void test1(){ // Standart ekleme ve silme işlemleri
    clock_t tStart = clock();

    CircularLinkedList test;

    for(int i=1; i<=100000; i++)
        test.insert(i);

    clock_t insertionTime = clock();
    clock_t t1 = insertionTime-tStart;

    for(int i=1; i<=100000; i++)
        test.deleteNode(i);

    clock_t deleteTime = clock();
    clock_t t2 = deleteTime-insertionTime;

    printf("Time taken: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    printf("Insertion Time: %.4fs\n", (double) t1 / CLOCKS_PER_SEC);
    printf("Delete Time: %.4fs\n", (double) t2 / CLOCKS_PER_SEC);
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
