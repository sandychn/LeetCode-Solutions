class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        seen = set()
        waiting = 0
        acculmated = 0
        for num in nums:
            acculmated = (acculmated + num) % k
            if acculmated in seen:
                return True
            seen.add(waiting)
            # 每个前缀和需要延迟一次循环后再加入seen, 因为题目要求子数组大小至少为2
            waiting = acculmated
        return False
