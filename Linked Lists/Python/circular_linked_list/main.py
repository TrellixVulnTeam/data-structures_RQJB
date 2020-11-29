import time


class CircularLinkedList:
    def __init__(self):
        self.head = None
        self.current = None

    def display(self):
        it = self.head
        print(it.value, end=" ")
        it = it.next
        while it is not self.head:
            print(it.value, end=" ")
            it = it.next
        print("")

    def insert(self, value):  # standart ekleme işlemi, listenin sonuna eklenir
        if self.head is None:
            self.head = Node(value)
            self.current = self.head
            self.head.next = self.head
        else:
            self.current.next = Node(value)
            self.current = self.current.next
            self.current.next = self.head

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
            self.current = self.head
            self.head.next = self.head
            return

        if value < self.head.value:
            temp = Node(self.head.value)
            temp.next = self.head.next
            self.head.next = temp
            self.head.value = value
            return

        it = self.head
        while it.next is not self.head and it.next.value < value:
            it = it.next

        temp = Node(value)
        temp.next = it.next
        it.next = temp
        return

    def deleteNode(self, value):
        if self.head is None:
            return

        if self.head.next == self.head and self.head.value == value:
            self.head = None
            return

        it = self.head

        if self.head.value == value:  # kökün silinme durumu
            while it.next != self.head:
                it = it.next

            it.next = self.head.next
            self.head = self.head.next
            return

        while it.next is not self.head and it.next.value != value:  # silinecek değerin önünde durur
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
            while it.next != self.head:
                it = it.next

            it.next = self.head.next
            self.head = self.head.next
            return

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
    start = time.time()
    cList = CircularLinkedList()
    for i in range(1000000):
        cList.insert(i)
    end = time.time()

    # cList.display()
    print("Time taken: ", end - start)


def test2():
    cList = CircularLinkedList()
    num = [3, 5, 4, 9, 12, 1, -5, 20, 99, -100]
    for i in range(len(num)):
        cList.insertInOrder(num[i])

    cList.display()
    cList.deleteNode(-100)
    cList.display()
    cList.deleteNode(-5)
    cList.display()


def test3():
    cList = CircularLinkedList()
    num = [5, 6, 7, 10, -5, 20, 3]
    for i in range(len(num)):
        cList.insert(num[i])

    cList.display()
    cList.insertTo(3, 50)
    cList.display()
    cList.deleteNodeAt(0)
    cList.display()


if __name__ == '__main__':
    # test1()
    # test2()
    test3()
