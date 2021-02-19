class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        current, cnt = None, 0
        for num in nums:
            if current == num:
                cnt += 1
            else:
                cnt -= 1
                if cnt <= 0:
                    current, cnt = num, 1
        return current if nums.count(current) * 2 > len(nums) else -1
