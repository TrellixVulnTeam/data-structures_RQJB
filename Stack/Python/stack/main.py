import time


class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None


class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def empty(self):
        if self.top is None:
            return True
        else:
            return False

    def push(self, value):
        if self.top is None:
            self.top = Node(value)
            self.size += 1
        else:
            temp = Node(value)
            temp.prev = self.top
            self.top = temp
            self.size += 1

    def pop(self):
        if self.empty():
            return None
        else:
            temp = self.top
            self.top = self.top.prev
            temp.prev = None
            self.size -= 1

    def getSize(self):
        return self.size

    def getTop(self):
        if self.empty():
            return None
        else:
            return self.top.value

    def display(self):
        if self.empty():
            print("Empty Stack")
        else:
            it = self.top
            while it is not None:
                print(it.value, "->", end="")
                it = it.prev
            print("")
            return


def test1():
    stack = Stack()

    for i in range(5):
        stack.push(i)

    stack.display()
    print("Size: ", stack.getSize())
    print("Top: ", stack.getTop())

    size = stack.getSize()
    for i in range(size):
        stack.pop()
        stack.display()


def test2():
    stack = Stack()
    begin = time.time()

    for i in range(100000000):
        stack.push(i)

    t1 = time.time()
    insertion = t1 - begin

    for i in range(100000000):
        stack.pop()

    end = time.time()
    deletion = end - t1
    elapsed = end - begin

    print("Insertion : {:.4f} s".format(insertion))
    print("Deletion : {:.4f} s".format(deletion))
    print("Time taken: {:.4f} s ".format(elapsed))


if __name__ == '__main__':
    # test1()
    test2()
