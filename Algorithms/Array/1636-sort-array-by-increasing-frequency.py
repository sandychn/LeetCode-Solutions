from functools import cmp_to_key
from collections import Counter
from typing import List


class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnter = Counter(nums)

        def compare(x, y):
            if cnter[x] < cnter[y]:
                return -1
            if cnter[x] > cnter[y]:
                return 1
            if x > y:
                return -1
            if x < y:
                return 1
            return 0

        return sorted(nums, key=cmp_to_key(compare))
