#include "AVLTree.cpp"

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(9);
    tree.insert(13);
    tree.insert(7);
    tree.insert(16);
    tree.insert(20);

    tree.printInorder();

    tree.remove(10);
    tree.printInorder();

    return 0;
}
