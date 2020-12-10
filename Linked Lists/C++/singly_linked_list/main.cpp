#include <iostream>
#include <vector>
#include <chrono>

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
        int counter{0};
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
   }


    void display(){
        if(head == nullptr)
            cout<<"empty list"<<endl;

        node *it=head;
        while (it!= nullptr){
            cout<<it->value<<" ";
            it=it->next;
        }
        cout<<endl;
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
   }

    void deleteNodeAt(int index){ // Indexteki elemanı silme
        node *it=head;
        node *temp;
        int counter{0};

        if(index==0){
            head=head->next;
            return;
        }

        while(counter!=index-1){
            it=it->next;
            counter++;
        }

        temp=it->next;
        it->next=it->next->next;
        free(temp);
   }
};

void test1(){ // Standart ekleme ve silme işlemleri
    auto begin = chrono::high_resolution_clock::now();

    LinkedList test;

    for(int i=1; i<=100000; i++)
        test.insert(i);

    auto t1 = chrono::high_resolution_clock::now();
    auto insertion = chrono::duration_cast<chrono::nanoseconds>(t1-begin);

    for(int i=1; i<=100000; i++)
        test.deleteNode(i);

    auto t2 = chrono::high_resolution_clock::now();
    auto deletion = chrono::duration_cast<chrono::nanoseconds>(t2-t1);
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(t2-begin);

    test.display();

    printf("Time Taken: %.4f s \n", elapsed.count()*1e-9 );
    printf("Insertion Time: %.4f s \n", insertion.count()*1e-9 );
    printf("Deletion Time: %.4f s \n", deletion.count()*1e-9);
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

void test4(){ //İstenen indexten elemean silme
    LinkedList test;
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    for(int num:vec)
        test.insertInOrder(num);

    test.display();
    test.deleteNodeAt(0); // kök silme durumu
    test.deleteNodeAt(5);// ara eleman silme
    test.deleteNodeAt(7);// son eleman silme
    test.display();
}
int main() {
    test1();
    //test2();
    //test3();
    //test4();

    return 0;
}
