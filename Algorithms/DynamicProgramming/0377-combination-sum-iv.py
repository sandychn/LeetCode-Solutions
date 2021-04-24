from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(target):
            for num in nums:
                # the answer is guaranteed to fit in a 32-bit integer, no need to calculate values >= (1 << 32)
                if i + num <= target and dp[i + num] + dp[i] < (1 << 32):
                    dp[i + num] += dp[i]
        return dp[target]
