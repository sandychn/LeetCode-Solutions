class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        m, n = len(M), len(M[0])
        res = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                total = cnt = 0
                for x in (i - 1, i, i + 1):
                    for y in (j - 1, j, j + 1):
                        if 0 <= x < m and 0 <= y < n:
                            total += M[x][y]
                            cnt += 1
                res[i][j] = total // cnt
        return res
