class MyHashMap:
    BUCKET_SIZE = 3331

    def __init__(self):
        self.buckets = [[] for _ in range(MyHashMap.BUCKET_SIZE)]


    def getBucket(self, key: int) -> list:
        return self.buckets[key % MyHashMap.BUCKET_SIZE]


    def put(self, key: int, value: int) -> None:
        bucket = self.getBucket(key)
        for element in bucket:
            if element[0] == key:
                element[1] = value
                return
        bucket.append([key, value])


    def get(self, key: int) -> int:
        for element in self.getBucket(key):
            if element[0] == key:
                return element[1]
        return -1


    def remove(self, key: int) -> None:
        bucket = self.getBucket(key)
        for i, e in enumerate(bucket):
            if e[0] == key:
                bucket.pop(i)
                return



# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
