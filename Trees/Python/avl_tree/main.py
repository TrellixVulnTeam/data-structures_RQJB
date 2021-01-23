import sys


# Create a tree node
class Node(object):
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1


class AVLTree(object):

    def insert(self, root, key):

        if not root:
            return Node(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))

        balance = self.getBalance(root)
        if balance > 1:
            if key < root.left.key:
                return self.rightRotate(root)
            else:
                root.left = self.leftRotate(root.left)
                return self.rightRotate(root)

        if balance < -1:
            if key > root.right.key:
                return self.leftRotate(root)
            else:
                root.right = self.rightRotate(root.right)
                return self.leftRotate(root)

        return root

    def delete(self, root, key):

        if not root:
            return root
        elif key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp
            temp = self.getMin(root.right)
            root.key = temp.key
            root.right = self.delete(root.right, temp.key)
        if root is None:
            return root

        root.height = 1 + max(self.getHeight(root.left), self.getHeight(root.right))

        balance = self.getBalance(root)

        if balance > 1:
            if self.getBalance(root.left) >= 0:
                return self.rightRotate(root)
            else:
                root.left = self.leftRotate(root.left)
                return self.rightRotate(root)
        if balance < -1:
            if self.getBalance(root.right) <= 0:
                return self.leftRotate(root)
            else:
                root.right = self.rightRotate(root.right)
                return self.leftRotate(root)
        return root

    def leftRotate(self, head):
        newHead = head.right
        head.right = newHead.left
        newHead.left = head
        head.height = 1 + max(self.getHeight(head.left), self.getHeight(head.right))
        newHead.height = 1 + max(self.getHeight(newHead.left), self.getHeight(newHead.right))
        return newHead

    def rightRotate(self, head):
        newHead = head.left
        head.left = newHead.right
        newHead.right = head
        head.height = 1 + max(self.getHeight(head.left), self.getHeight(head.right))
        newHead.height = 1 + max(self.getHeight(newHead.left), self.getHeight(newHead.right))
        return newHead

    def getHeight(self, root):
        if not root:
            return 0
        return root.height

    def getBalance(self, root):
        if not root:
            return 0
        return self.getHeight(root.left) - self.getHeight(root.right)

    def getMin(self, root):
        if root is None or root.left is None:
            return root
        return self.getMin(root.left)

    def inOrder(self, root):
        if not root:
            return
        self.inOrder(root.left)
        print("{0} ".format(root.key), end="")
        self.inOrder(root.right)


if __name__ == '__main__':
    tree = AVLTree()
    root = None
    values = [33, 13, 52, 9, 21, 61, 8, 11]
    for value in values:
        root = tree.insert(root, value)

    tree.inOrder(root)