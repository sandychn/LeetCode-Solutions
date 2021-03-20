from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left + 1 < right:
            mid = (left + right) // 2
            if nums[mid] <= target:
                left = mid
            else:
                right = mid
        value = nums[left]
        return left if target <= value else right


def tester():
    print(Solution().searchInsert([1, 3, 5, 6], 5))  # => 2
    print(Solution().searchInsert([1, 3, 5, 6], 2))  # => 1
    print(Solution().searchInsert([1, 3, 5, 6], 7))  # => 4
    print(Solution().searchInsert([1, 3, 5, 6], 0))  # => 0
