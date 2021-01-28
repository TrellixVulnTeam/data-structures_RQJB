#ifndef SPLAY_TREE_SPLAYTREE_H
#define SPLAY_TREE_SPLAYTREE_H

using namespace std;

struct node {
    int data;
    node *parent, *left, *right;

    node(){}
    node(int &value):data(value){
        parent=nullptr;
        left=nullptr;
        right=nullptr;
    }
    ~node(){}
};

class SplayTree {
private:
    node* root;
    node* searchTreeBase(node* node, int key);
    void deleteNodeBase(node* node, int key);
    void leftRotate(node* x);
    void rightRotate(node* x);
    void splay(node* x);
    node* join(node* s, node* t);
    void split(node* &x, node* &s, node* &t);
    void printBase(node* Node, string indent, bool last);
public:
    SplayTree():root{nullptr}{}
    
    
    node* searchTree(int k) {
        node* x = searchTreeBase(this->root, k);
        if (x) {
            splay(x);
        }
        return x;
    }

    node* minimum(node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    node* maximum(node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    void insert(int key) {
        // BST insert
        node* Node = new node(key);
        node* y = nullptr;
        node* x = this->root;

        while (x != nullptr) {
            y = x;
            if (Node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // y is parent of x
        Node->parent = y;
        if (y == nullptr) {
            root = Node;
        } else if (Node->data < y->data) {
            y->left = Node;
        } else {
            y->right = Node;
        }

        // splay the node
        splay(Node);
    }

    node* getRoot(){
        return this->root;
    }

    void deleteNode(int data) {
        deleteNodeBase(this->root, data);
    }

    void printTree() {
        printBase(this->root, "", true);
    }
};

#endif //SPLAY_TREE_SPLAYTREE_H
