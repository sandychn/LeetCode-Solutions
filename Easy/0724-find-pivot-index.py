class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        left = 0
        for idx, num in enumerate(nums):
            right = total - num - left
            if left == right:
                return idx
            left += num
        return -1
