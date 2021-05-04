MAX_VAL = 1000

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        summary = [0] * (MAX_VAL + 1)
        for num in nums:
            summary[num] += num

        first, second = summary[0], max(summary[0], summary[1])
        for i in range(2, MAX_VAL + 1):
            first, second = second, max(second, first + summary[i])
        return second
