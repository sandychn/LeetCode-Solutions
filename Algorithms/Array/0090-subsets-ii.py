class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = set()
        n = len(nums)
        for i in range(1 << n):
            elements = [num for idx, num in enumerate(nums) if (i & (1 << idx))]
            res.add(tuple(elements))
        return [[*tup] for tup in res]
