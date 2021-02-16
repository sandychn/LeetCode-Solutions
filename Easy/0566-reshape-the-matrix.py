class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        n, m = len(nums), len(nums[0])
        if n * m != r * c:
            return nums
        res = [[0] * c for _ in range(r)]
        for i in range(n * m):
            res[i // c][i % c] = nums[i // m][i % m]
        return res
