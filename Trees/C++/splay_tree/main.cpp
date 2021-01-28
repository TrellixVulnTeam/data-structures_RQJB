#include <iostream>
#include "SplayTree.h"
#include "SplayTree.cpp"

using namespace std;
int main()
{
    SplayTree tree;
    tree.insert(33);
    tree.insert(44);
    tree.insert(67);
    tree.insert(98);
    tree.insert(1);
    tree.printTree();
    tree.searchTree(33);
    tree.printTree();
    tree.searchTree(44);
    tree.printTree();
    tree.searchTree(98);
    tree.printTree();
    tree.searchTree(44);
    tree.printTree();

    return 0;
}
