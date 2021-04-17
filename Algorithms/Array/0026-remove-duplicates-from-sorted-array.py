class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        for v in nums:
            if count == 0 or nums[count - 1] != v:
                nums[count] = v
                count += 1
        return count
