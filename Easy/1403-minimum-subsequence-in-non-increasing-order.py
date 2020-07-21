class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums_sum = sum(nums)
        nums.sort(reverse=True)
        now = 0
        for i, num in enumerate(nums):
            now += num
            if now > nums_sum - now:
                return nums[:i+1]
