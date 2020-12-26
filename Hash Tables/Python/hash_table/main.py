class HashItem:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class HashTable:
    def __init__(self, size):
        self.size = size
        self.slots = [None for i in range(self.size)]
        self.count = 0
        self.loadFactor = self.count / self.size  # gives us an indication of how large a portion of the available slots are being used

    def _hash(self, key):  # generates the hash value of a string
        multiplier = 1
        hash_value = 0
        for ch in key:
            hash_value += multiplier * ord(ch)
            multiplier += 1
        return hash_value % self.size

    def put(self, key, value):
        item = HashItem(key, value)
        h = self._hash(key)

        while self.slots[h] is not None:
            if self.slots[h].key is key:
                break
            h = (h + 1) % self.size

        if self.slots[h] is None:
            self.count += 1
        self.slots[h] = item

    def get(self, key):
        h = self._hash(key)

        while self.slots[h] is not None:
            if self.slots[h].key is key:
                return self.slots[h].value
            h = (h + 1) % self.size

        return None

    def delete(self, key):
        h = self._hash(key)
        while self.slots[h] is not None:
            if self.slots[h].key is key:
                self.slots[h].value = None
                self.slots[h].key = None
                return
            h = (h + 1) % self.size

        print("Key not found")

    def __setitem__(self, key, value):
        self.put(key, value)

    def __getitem__(self, item):
        return self.get(key)


if __name__ == '__main__':
    print(sum(map(ord, 'hello world')))  # hash of the whole string

    ht = HashTable(256)
    ht.put("test", "input")
    ht.put("ad", "collision-test")
    ht.put("ga", "collision-test2")
    ht.put("test2", "input2")

    for key in ("test", "ad", "test3", "ga", "test2"):
        v = ht.get(key)
        print(v)

    print("\n********")
    ht["test4"] = "input4"

    for key in ("test", "ad", "test3", "ga", "test2", "test4"):
        v = ht.get(key)
        print(v)

    print("\n********")
    print(f"The number of elements is: {ht.count}")
    ht.delete("test2")
    for key in ("test", "ad", "test3", "ga", "test2", "test4"):
        v = ht.get(key)
        print(v)

    ht.delete("test2")
    dict = {"test5": "input5"}  # also dictionary data types can be used to implement hash tables
