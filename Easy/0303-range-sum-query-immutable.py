class NumArray:

    def __init__(self, nums: List[int]):
        prefix_sum = [0] * (len(nums) + 1)
        for i, v in enumerate(nums):
            prefix_sum[i + 1] = prefix_sum[i] + v
        self.prefix_sum = prefix_sum

    def sumRange(self, i: int, j: int) -> int:
        return self.prefix_sum[j + 1] - self.prefix_sum[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
