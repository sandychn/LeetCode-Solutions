from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """Do not return anything, modify matrix in-place instead."""
        if not matrix:
            return
        is_first_col_has_zero = False
        row, col = len(matrix), len(matrix[0])
        for i in range(row):
            if matrix[i][0] == 0:
                is_first_col_has_zero = True
            for j in range(1, col):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        for i in range(row - 1, -1, -1):
            for j in range(1, col):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if is_first_col_has_zero:
                matrix[i][0] = 0
