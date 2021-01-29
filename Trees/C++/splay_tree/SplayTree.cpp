#include "SplayTree.h"
#include <iostream>

node *SplayTree::searchTreeBase(node* Node, int key) {
    if (Node == nullptr || key == Node->data) {
        return Node;
    }

    if (key < Node->data) {
        return searchTreeBase(Node->left, key);
    }
    return searchTreeBase(Node->right, key);
}

void SplayTree::deleteNodeBase(node* Node, int key) {
    node *x = nullptr;
    node *t, *s;
    while (Node != nullptr){
        if (Node->data == key) {
            x = Node;
        }

        if (Node->data <= key) {
            Node = Node->right;
        } else {
            Node = Node->left;
        }
    }

    if (x == nullptr) {
        cout<<"Couldn't find the key in the tree"<<endl;
        return;
    }
    split(x, s, t);
    if (s->left){ // remove x
        s->left->parent = nullptr;
    }
    root = join(s->left, t);
    free(s);
    s = nullptr;
}

void SplayTree::leftRotate(node* x) {
    node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void SplayTree::rightRotate(node* x) {
    node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void SplayTree::splay(node* x) {
    while (x->parent) {
        if (!x->parent->parent) {
            if (x == x->parent->left) {
                // zig rotation
                rightRotate(x->parent);
            } else {
                // zag rotation
                leftRotate(x->parent);
            }
        } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
            // zig-zig rotation
            rightRotate(x->parent->parent);
            rightRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
            // zag-zag rotation
            leftRotate(x->parent->parent);
            leftRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
            // zig-zag rotation
            leftRotate(x->parent);
            rightRotate(x->parent);
        } else {
            // zag-zig rotation
            rightRotate(x->parent);
            leftRotate(x->parent);
        }
    }
}


node *SplayTree::join(node* s, node* t){
    if (!s) {
        return t;
    }

    if (!t) {
        return s;
    }
    node* x = maximum(s);
    splay(x);
    x->right = t;
    t->parent = x;
    return x;
}

void SplayTree::split(node* &x, node* &s, node* &t) {
    splay(x);
    if (x->right) {
        t = x->right;
        t->parent = nullptr;
    } else {
        t = nullptr;
    }
    s = x;
    s->right = nullptr;
    x = nullptr;
}

void SplayTree::printBase(node* Node, string indent, bool last){
    if (Node != nullptr) {
        std::cout<<indent;
        if (last) {
            std::cout<<"└────";
            indent += "     ";
        } else {
            std::cout<<"├────";
            indent += "|    ";
        }

        std::cout<<Node->data<<std::endl;

        printBase(Node->left, indent, false);
        printBase(Node->right, indent, true);
    }
}

