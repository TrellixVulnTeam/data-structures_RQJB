import time


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enque(self, value):
        if self.head is None:
            self.head = Node(value)
            self.tail = self.head
        else:
            self.tail.next = Node(value)
            self.tail = self.tail.next

    def deque(self):
        if self.head is None:
            print("Empty queue")
        elif self.head.next is not None:
            self.head = self.head.next
        else:
            self.head = None

    def display(self):
        if self.head is None:
            print("Empty queue")
            return

        it = self.head
        while it is not None:
            print(it.value, end="->")
            it = it.next

        print("")

    def isEmpty(self):
        return self.head is None


def test1():
    queue = Queue()

    for i in range(10):
        queue.enque(i)
        queue.display()

    print(queue.isEmpty())

    for i in range(10):
        queue.deque()
        queue.display()

    queue.deque()
    print(queue.isEmpty())


def test2():
    queue = Queue()
    begin = time.time()

    for i in range(1000000):
        queue.enque(i)

    t1 = time.time()
    insertion = t1 - begin

    for i in range(1000000):
        queue.deque()

    end = time.time()
    deletion = end - t1
    elapsed = end - begin

    print("Insertion : {:.4f} s".format(insertion))
    print("Deletion : {:.4f} s".format(deletion))
    print("Time taken: {:.4f} s ".format(elapsed))


if __name__ == '__main__':
    # test1()
    test2()

