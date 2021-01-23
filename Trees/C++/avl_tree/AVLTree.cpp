#include<iostream>
using namespace std;

struct node{
    int key,height;
    node *left, *right;

    explicit node(int &value):key{value},height{1},left{nullptr},right{nullptr}{}
};

class AVLTree{
public:

    node * root{nullptr};
    void insert(int value){
        root=insert(root, value);
    }
    void remove(int value){
        root=remove(root, value);
    }
    void printInorder(){
        inOrder(root);
        cout<<endl;
    }
private:
    static int height(node * head){
        if(head==nullptr) return 0;
        return head->height;
    }
    static node * rightRotation(node * head){
        node *newHead = head->left;
        head->left = newHead->right;
        newHead->right = head;
        head->height = 1+max(height(head->left), height(head->right));
        newHead->height = 1+max(height(newHead->left), height(newHead->right));
        return newHead;
    }

    static node * leftRotation(node * head){
        node * newHead = head->right;
        head->right = newHead->left;
        newHead->left = head;
        head->height = 1+max(height(head->left), height(head->right));
        newHead->height = 1+max(height(newHead->left), height(newHead->right));
        return newHead;
    }

    void inOrder(node * head){
        if(head== nullptr)
            return ;
        inOrder(head->left);
        cout<<head->key<<" ";
        inOrder(head->right);
    }

    node * insert(node * head, int value){
        if(head== nullptr){
            node * temp = new node(value);
            return temp;
        }
        if(value < head->key)
            head->left = insert(head->left, value);
        else if(value > head->key)
            head->right = insert(head->right, value);

        head->height = 1 + max(height(head->left), height(head->right));
        int balance = height(head->left) - height(head->right);

        if(balance>1){
            if(value < head->left->key){
                return rightRotation(head);
            }else{
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }else if(balance<-1){
            if(value > head->right->key){
                return leftRotation(head);
            }else{
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
    static node * remove(node * head, int value){
        if(head==nullptr)
            return nullptr;
        if(value < head->key){
            head->left = remove(head->left, value);
        }else if(value > head->key){
            head->right = remove(head->right, value);
        }else{
            node * right = head->right;
            if(head->right==nullptr){
                node * left = head->left;
                free(head);
                head = left;
            }else if(head->left==nullptr){
                free(head);
                head = right;
            }else{
                while(right->left!=nullptr)
                    right = right->left;
                head->key = right->key;
                head->right = remove(head->right, right->key);
            }
        }
        if(head==nullptr)
            return head;
        
        head->height = 1 + max(height(head->left), height(head->right));
        int balance = height(head->left) - height(head->right);
        
        if(balance>1){
            if(value > head->left->key){
                return rightRotation(head);
            }else{
                head->left = leftRotation(head->left);
                return rightRotation(head);
            }
        }else if(balance < -1){
            if(value < head->right->key){
                return leftRotation(head);
            }else{
                head->right = rightRotation(head->right);
                return leftRotation(head);
            }
        }
        return head;
    }
};