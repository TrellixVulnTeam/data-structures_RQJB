import sys


class Node:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None


class SplayTree:
    def __init__(self):
        self.root = None

    def print_base(self, node, indent, last):
        if node is not None:
            sys.stdout.write(indent)
            if last:
                sys.stdout.write("R----")
                indent += "     "
            else:
                sys.stdout.write("L----")
                indent += "|    "

            print(node.data)

            self.print_base(node.left, indent, False)
            self.print_base(node.right, indent, True)

    def search_tree_base(self, node, key):
        if node is None or key is node.data:
            return node

        if key < node.data:
            return self.search_tree_base(node.left, key)
        return self.search_tree_base(node.right, key)

    def delete_node_base(self, node, key):
        x = None
        t = None
        s = None
        while node is not None:
            if node.data is key:
                x = node

            if node.data <= key:
                node = node.right
            else:
                node = node.left

        if x is None:
            print("Couldn't find the key in the tree")
            return

        self.splay(x)
        if x.right is not None:
            t = x.right
            t.parent = None
        else:
            t = None

        s = x
        s.right = None
        x = None

        # join operation
        if s.left is not None:
            s.left.parent = None

        self.root = self.join(s.left, t)
        s = None

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left is not None:
            y.left.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x is x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right is not None:
            y.right.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x is x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y

        y.right = x
        x.parent = y

    def splay(self, x):
        while x.parent is not None:
            if x.parent.parent is None:
                if x is x.parent.left:
                    # zig rotation
                    self.right_rotate(x.parent)
                else:
                    # zag rotation
                    self.left_rotate(x.parent)
            elif x is x.parent.left and x.parent is x.parent.parent.left:
                # zig-zig rotation
                self.right_rotate(x.parent.parent)
                self.right_rotate(x.parent)
            elif x is x.parent.right and x.parent is x.parent.parent.right:
                # zag-zag rotation
                self.left_rotate(x.parent.parent)
                self.left_rotate(x.parent)
            elif x is x.parent.right and x.parent is x.parent.parent.left:
                # zig-zag rotation
                self.left_rotate(x.parent)
                self.right_rotate(x.parent)
            else:
                # zag-zig rotation
                self.right_rotate(x.parent)
                self.left_rotate(x.parent)

    # joins two trees s and t
    def join(self, s, t):
        if s is None:
            return t

        if t is None:
            return s

        x = self.maximum(s)
        self.splay(x)
        x.right = t
        t.parent = x
        return x

    def search_tree(self, k):
        x = self.search_tree_base(self.root, k)
        if x is not None:
            self.splay(x)

    def minimum(self, node):
        while node.left is not None:
            node = node.left
        return node

    def maximum(self, node):
        while node.right is not None:
            node = node.right
        return node

    def insert(self, key):
        node = Node(key)
        y = None
        x = self.root

        while x is not None:
            y = x
            if node.data < x.data:
                x = x.left
            else:
                x = x.right

        node.parent = y
        if y is None:
            self.root = node
        elif node.data < y.data:
            y.left = node
        else:
            y.right = node

        self.splay(node)

    def delete_node(self, data):
        self.delete_node_base(self.root, data)

    def print_tree(self):
        self.print_base(self.root, "", True)


if __name__ == '__main__':
    tree = SplayTree()
    tree.insert(28)
    tree.insert(92)
    tree.insert(15)
    tree.insert(3)
    tree.insert(83)
    tree.insert(41)
    tree.insert(57)
    tree.insert(2)
    tree.print_tree()

    tree.search_tree(33)
    tree.print_tree()
    tree.search_tree(83)
    tree.print_tree()
    tree.search_tree(15)
    tree.print_tree()
