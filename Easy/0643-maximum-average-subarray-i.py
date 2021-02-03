class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        first = 0
        last = k - 1
        ans = now = sum(nums[first:last+1])
        while last + 1 < len(nums):
            now -= nums[first]
            first += 1
            last += 1
            now += nums[last]
            ans = max(ans, now)
        return ans / k
