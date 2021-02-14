class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.size = [1] * size
        self.count = size
    
    def get_parent(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.get_parent(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        x, y = self.get_parent(x), self.get_parent(y)
        if x == y:
            return False
        if self.size[x] > self.size[y]:
            x, y = y, x
        self.parent[x] = y
        self.size[y] += self.size[x]
        self.count -= 1
        return True
    
    def same(self, x, y):
        return self.get_parent(x) == self.get_parent(y)


class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        uf = UnionFind(n // 2)
        for i in range(0, n, 2):
            uf.union(row[i] // 2, row[i + 1] // 2)
        return n // 2 - uf.count
