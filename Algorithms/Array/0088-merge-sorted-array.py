from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """Do not return anything, modify nums1 in-place instead."""
        i, j = m - 1, n - 1
        for k in range(n + m - 1, -1, -1):
            if i >= 0 and (j < 0 or nums1[i] > nums2[j]):
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1


l = [1, 2, 3, 0, 0, 0]
Solution().merge(l,3,[2,5,6],3)
print(l)
