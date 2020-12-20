from Heap import MinHeap


def test1():
    maxHeap = MinHeap()

    nums = [5, 2, 6, 4, 3, 7, 1, 8]
    for num in nums:
        maxHeap.insert(num)

    maxHeap.display()


if __name__ == '__main__':
    test1()
