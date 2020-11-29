import time


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.current = None

    def display(self):
        it = self.head
        while it is not None:
            print(it.value, end=" ")
            it = it.next
        print("")

    def displayReverse(self):
        it = self.current

        while it is not self.head:
            print(it.value, end=" ")
            it = it.prev

        print(it.value, end=" ")
        print("")

    def insert(self, value):  # standart ekleme işlemi, listenin sonuna eklenir
        if self.head is None:
            self.head = Node(value)
            self.head.next = None
            self.head.prev = None
            self.current = self.head
            return
        else:
            temp = self.current
            self.current.next = Node(value)
            self.current = self.current.next
            self.current.prev = temp

    def insertTo(self, index, value):
        counter = 0
        it = self.head

        if index == 0:
            temp = Node(self.head.value)
            temp.next = self.head.next
            self.head.next.prev = temp
            self.head.next = temp
            temp.prev = self.head
            self.head.value = value
            return

        while counter != index - 1:
            it = it.next
            counter += 1

        temp = Node(value)
        temp.next = it.next
        it.next.prev = temp
        it.next = temp
        temp.prev = it

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
        temp.prev = it
        if temp.next is not None:
            temp.next.prev = temp

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
        self.prev = None


def test1():
    start = time.time()
    dList = DoublyLinkedList()
    for i in range(100000):
        dList.insert(i)
    insertionTime = time.time() - start
    for i in range(100000):
        dList.deleteNode(i)

    print("Time taken: {:.4f}".format(time.time() - start))
    print("Insertion Time: {:.4f}".format(insertionTime))


def test2():
    dList = DoublyLinkedList()
    num = [5, 6, 7, 10, -5, 20, 3, 2, -10]
    for i in range(len(num)):
        dList.insertInOrder(num[i])

    dList.display()


def test3():
    dList = DoublyLinkedList()
    num = [5, 6, 7, 10, -5, 20, 3]
    for i in range(len(num)):
        dList.insert(num[i])

    dList.display()
    dList.insertTo(3, 50)
    dList.display()
    dList.deleteNodeAt(3)
    dList.insertTo(0, 22)
    dList.display()


if __name__ == '__main__':
    # test1()
    test2()
    # test3()
