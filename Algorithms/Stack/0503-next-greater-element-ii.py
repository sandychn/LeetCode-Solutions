class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        stack = []
        result = [-1] * n
        for i in range(n * 2):
            value = nums[i % n]
            while stack and nums[stack[-1] % n] < value:
                result[stack.pop() % n] = value
            stack.append(i)
        return result
