from heapq import heappush, heappop


class MinHeap:
    def __init__(self):
        self.heap = []
        self.size = 0

    def parent(self, i):
        return (i - 1) / 2

    def insert(self, key):
        self.size += 1
        heappush(self.heap, key)

    def decreaseKey(self, i, key):
        self.heap[i] = key

        while i != 0 and self.heap[self.parent(i)] > self.heap[i]:
            self.heap[i], self.heap[self.parent(i)] = (self.heap[self.parent(i)], self.heap[i])

    def extractMin(self):
        self.size -= 1
        return heappop(self.heap)

    def getMin(self):
        return self.heap[0]

    def display(self):
        for i in range(self.size):
            print(self.heap[i], end=" ")
        print("")

