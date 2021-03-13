class MyHashSet:
    BUCKET_SIZE = 3331

    def __init__(self):
        self.buckets = [[] for _ in range(MyHashSet.BUCKET_SIZE)]


    def add(self, key: int) -> None:
        bucket = self.buckets[key % MyHashSet.BUCKET_SIZE]
        if key not in bucket:
            bucket.append(key)


    def remove(self, key: int) -> None:
        bucket = self.buckets[key % MyHashSet.BUCKET_SIZE]
        try:
            bucket.remove(key)
        except ValueError:
            pass


    def contains(self, key: int) -> bool:
        return key in self.buckets[key % MyHashSet.BUCKET_SIZE]



# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
