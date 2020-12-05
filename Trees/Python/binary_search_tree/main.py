import random


class Node:
    def __init__(self, value=None):
        self.key = value
        self.right = None
        self.left = None
        self.parent = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        temp = None
        it = self.root

        while it is not None:
            temp = it
            if value.key < it.key:
                it = it.left
            else:
                it = it.right

        value.parent = temp
        if temp is None:
            self.root = value
        elif value.key < temp.key:
            temp.left = value
        else:
            temp.right = value

    def transplant(self, u, v):
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v

        if v is not None:
            v.parent = u.parent

    def minimum(self, value):
        while value.left is not None:
            value = value.left
        return value

    def max(self, value):
        while value.right is not None:
            value = value.right
        return value

    def deleteNode(self, value):
        if value.left is None:
            self.transplant(value, value.right)
        elif value.rightt is None:
            self.transplant(value, value.left)
        else:
            temp = self.minimum(value.right)
            if temp.parent is not value:
                self.transplant(temp, temp.right)
                temp.right = value.right
                temp.right.parent = temp
            self.transplant(value, temp)
            temp.left = value.left
            temp.left.parent = temp

    def InOrderTraversal(self, value):
        if value is not None:
            self.InOrderTraversal(value.left)
            print(value.key, end=" ")
            self.InOrderTraversal(value.right)

    def preOrderTraversal(self, value):
        if value is not None:
            print(value.key, end=" ")
            self.InOrderTraversal(value.left)
            self.InOrderTraversal(value.right)

    def postOrderTraversal(self, value):
        if value is not None:
            self.InOrderTraversal(value.left)
            self.InOrderTraversal(value.right)
            print(value.key, end=" ")

    def BreadthFirstSearch(self, value):
        if value is not None:
            nodes = [value]
            while not nodes:
                temp = nodes.pop()
                print(temp.key, end=" ")
                if temp.left is not None:
                    nodes.append(temp.left)
                if temp.right is not None:
                    nodes.append(temp.right)

    def getRoot(self):
        return self.root


def test1():
    bst = BinarySearchTree()
    nodes = []
    for i in range(8):
        randNum = random.randint(1, 70)
        nodes.append(Node(randNum))
        bst.insert(nodes[i])

    print("InOrderTraversal")
    bst.InOrderTraversal(bst.getRoot())

    print("\npreOrderTraversal")
    bst.preOrderTraversal(bst.getRoot())

    print("\npostOrderTraversal")
    bst.postOrderTraversal(bst.getRoot())

    print("\nBreadthFirstSearch")
    bst.BreadthFirstSearch(bst.getRoot())

    bst.deleteNode(nodes[5])
    print("InOrderTraversal")
    bst.InOrderTraversal(bst.getRoot())


if __name__ == '__main__':
    test1()
