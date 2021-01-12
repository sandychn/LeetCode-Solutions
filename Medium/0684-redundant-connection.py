class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        father = list(range(n + 1))

        def find(x):
            if father[x] != x:
                father[x] = find(father[x])
            return father[x]
        
        for x, y in edges:
            rootx, rooty = find(x), find(y)
            if rootx == rooty:
                return [x, y]
            father[rootx] = rooty
        
        return []
