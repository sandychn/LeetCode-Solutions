from typing import List


class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        modified = None
        cnt = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                if i == 0:
                    modified = (i, nums[i])
                    nums[i] = nums[i + 1]
                else:
                    if nums[i - 1] <= nums[i + 1]:
                        modified = (i, nums[i])
                        nums[i] = nums[i + 1]
                    else:
                        modified = (i + 1, nums[i + 1])
                        nums[i + 1] = nums[i]
                cnt += 1
                if cnt > 1:
                    break
        if modified:
            nums[modified[0]] = modified[1]
        return cnt <= 1


def tester():
    print(Solution().checkPossibility([4, 2, 3])) # => True [2, 2, 3]
    print(Solution().checkPossibility([4, 2, 1])) # => False
    print(Solution().checkPossibility([3, 4, 2, 3])) # => False
    print(Solution().checkPossibility([5, 7, 1, 8])) # => True [5, 7, 7, 8]
    print(Solution().checkPossibility([-1, 4, 2, 3])) # => True [-1, 2, 2, 3]
    print(Solution().checkPossibility([1, 4, 1, 2])) # => True [1, 1, 1, 2]
