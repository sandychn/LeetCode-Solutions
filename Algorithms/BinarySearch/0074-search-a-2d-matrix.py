class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])  # 3, 4
        l, r = 0, m * n
        while l + 1 < r:
            mid = (l + r) // 2
            x = mid // n
            y = mid % n
            if matrix[x][y] > target:
                r = mid
            else:
                l = mid
        return l < m * n and matrix[l // n][l % n] == target
