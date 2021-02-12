class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        for v in nums:
            v = abs(v)
            nums[v - 1] = -abs(nums[v - 1])
        res = [(i + 1) for i in range(len(nums)) if nums[i] > 0]
        # restore values in the array
        for i in range(len(nums)):
            nums[i] = abs(nums[i])
        return res
