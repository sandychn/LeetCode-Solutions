class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        row = len(matrix)
        col = len(matrix[0]) if row else 0
        arr = [[0] * (col + 1) for _ in range(row + 1)]
        for i in range(row):
            for j in range(col):
                arr[i + 1][j + 1] = arr[i + 1][j] + arr[i][j + 1] - arr[i][j] + matrix[i][j]
        self.arr = arr

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        arr = self.arr
        return arr[row2 + 1][col2 + 1] - arr[row2 + 1][col1] - arr[row1][col2 + 1] + arr[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
