#include <iostream>
#include <vector>

using namespace std;

class LinkedList{
private:
    struct node{
        int value;
        node *next;

        node();
        node(int &value) :value(value){}
        ~node();
    };

    node *head, *current;
public:
    LinkedList(){
        head=nullptr;
        current=nullptr;
    }
    ~LinkedList(){}

    void insert(int value){ // ekleme
        if(head==nullptr){
            head=new node(value);
            current=head;
        }else{
            current->next=new node(value);
            current=current->next;
        }
    }

    void insert(int index,int value){ // İstenen indexe ekleme
        int counter=0;
        node *it=head;

        while(counter!=index-1){
            it=it->next;
            counter++;
        }

        node *temp= new node(value);
        temp->next=it->next;
        it->next=temp;
    }

    void insertInOrder(int value){ //sıralı ekleme
        if(head==nullptr){ // empty case
            head=new node(value);
            current=head;
            return;
        }

        if(head->value > value){ // ilk elemandan küçük olma durumu, root değişiyor
            node *temp = new node(head->value);
            temp->next=head->next->next;
            head->next=temp;
            head->value=value;
            return;
        }

        node *it=head;
        while(it->next != nullptr && it->next->value < value){ // aranan değerin bir önceki değerinde durur
            it=it->next;
        }

        node *temp = new node(value);
        temp->next=it->next;
        it->next=temp;
        return;
    }


    void display(){
        if(head == nullptr)
            cout<<"empty list"<<endl;

        node *it=head;
        while (it!= nullptr){
            cout<<it->value<<" ";
            it=it->next;
        }
    }

    void  deleteNode(int value){
        node *it=head;
        node *temp;

        if(head->value == value){ // kökün silinme durumu
            head=head->next;
            return;
        }

        while (it->next != nullptr && it->next->value != value){ //silinecek değerin önünde durur
            it=it->next;
        }

        if(it->next == nullptr) {
            cout << "Value not found" << endl;
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

    LinkedList test;

    for(int i=1; i<=1000000; i++)
        test.insert(i);

    clock_t insertionTime = clock();
    clock_t t1 = insertionTime-tStart;

    for(int i=1; i<=1000000; i++)
        test.deleteNode(i);

    clock_t deleteTime = clock();
    clock_t t2 = deleteTime-insertionTime;

    test.display();

    printf("Time taken: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    printf("Insertion Time: %.4fs\n", (double) t1 / CLOCKS_PER_SEC);
    printf("Delete Time: %.4fs\n", (double) t2 / CLOCKS_PER_SEC);
}

void test2(){ //Sıralı ekleme
    LinkedList test;
    vector<int> vec{3,5,4,9,12,2,10,1,-5,13,7};

    for(int num:vec)
        test.insertInOrder(num);

    test.deleteNode(-5); //kök silme
    test.display();
}

void test3(){ //İstenen indexe ekleme
    LinkedList test;
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    for(int num:vec)
        test.insertInOrder(num);

    test.insert(4,20);
    test.display();
}

int main() {
    //test1();
    //test2();
    test3();
    return 0;
}
