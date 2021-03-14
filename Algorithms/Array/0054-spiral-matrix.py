from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        res = []
        x = y = b = 0
        while len(res) < m * n:
            for y in range(b, n - b):
                res.append(matrix[x][y])
            if len(res) >= m * n:
                break
            for x in range(b + 1, m - b):
                res.append(matrix[x][y])
            if len(res) >= m * n:
                break
            for y in range(n - b - 2, b - 1, -1):
                res.append(matrix[x][y])
            if len(res) >= m * n:
                break
            for x in range(m - b - 2, b, -1):
                res.append(matrix[x][y])
            b += 1
        return res
