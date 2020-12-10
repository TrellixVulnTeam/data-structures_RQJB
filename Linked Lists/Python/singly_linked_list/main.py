import time


class LinkedList:
    def __init__(self):
        self.head = None
        self.current = None

    def display(self):
        it = self.head
        while it is not None:
            print(it.value, end=" ")
            it = it.next
        print("")

    def insert(self, value):  # standart ekleme işlemi, listenin sonuna eklenir
        if self.head is None:
            self.head = Node(value)
            self.current = self.head
        else:
            self.current.next = Node(value)
            self.current = self.current.next

    def insertTo(self, index, value):
        counter = 0
        it = self.head

        while counter != index - 1:
            it = it.next
            counter += 1

        temp = Node(value)
        temp.next = it.next
        it.next = temp

    def insertInOrder(self, value):  # sıralı ekleme
        if self.head is None:
            self.head = Node(value)
            return

        if value < self.head.value:
            temp = Node(self.head.value)
            temp.next = self.head.next.next
            self.head.next = temp
            self.head.value = value
            return

        it = self.head
        while it.next is not None and it.next.value < value:
            it = it.next

        temp = Node(value)
        temp.next = it.next
        it.next = temp
        return

    def deleteNode(self, value):
        it = self.head

        if self.head.value == value:  # kökün silinme durumu
            self.head = self.head.next
            return

        while it.next is not None and it.next.value != value:  # silinecek değerin önünde durur
            it = it.next

        if it.next is None:
            print("Value not found")
            return

        it.next = it.next.next
        return

    def deleteNodeAt(self, index):  # Verilen indexteki elemanı silme
        counter = 0
        it = self.head

        if index == 0:
            self.head = self.head.next

        while counter != index - 1:
            it = it.next
            counter += 1

        it.next = it.next.next


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

    def setValue(self, value):
        self.value = value

    def getValue(self):
        return self.value

    def setNext(self, next):
        self.next = next

    def getNext(self):
        return self.next


def test1():
    begin = time.time()

    linkedlist = LinkedList()
    for i in range(100000000):
        linkedlist.insert(i)

    t1 = time.time()
    insertion = t1 - begin

    for i in range(100000000):
        linkedlist.deleteNode(i)

    end = time.time()
    deletion = end - t1
    elapsed = end - begin

    print("Insertion : {:.4f} s".format(insertion))
    print("Deletion : {:.4f} s".format(deletion))
    print("Time taken: {:.4f} s ".format(elapsed))


def test2():
    linkedlist = LinkedList()
    num = [5, 6, 7, 10, -5, 20, 3]
    for i in range(len(num)):
        linkedlist.insertInOrder(num[i])

    linkedlist.display()


def test3():
    linkedlist = LinkedList()
    num = [5, 6, 7, 10, -5, 20, 3]
    for i in range(len(num)):
        linkedlist.insert(num[i])

    linkedlist.display()
    linkedlist.insertTo(3, 50)
    linkedlist.display()
    linkedlist.deleteNodeAt(3)
    linkedlist.display()


if __name__ == '__main__':
    test1()
    # test2()
    # test3()
