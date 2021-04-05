class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = cnt = 0
        for j in range(len(nums)):
            if j > 0 and nums[j] == nums[j - 1]:
                cnt += 1
            else:
                cnt = 1
            if cnt <= 2:
                nums[i] = nums[j]
                i += 1
        return i
