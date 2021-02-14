class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ones = ans = 0
        for num in nums:
            if num == 1:
                ones += 1
                ans = max(ans, ones)
            else:
                ones = 0
        return ans
