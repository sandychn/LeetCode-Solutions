class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        val = 0
        res = [None] * len(A)
        for i, v in enumerate(A):
            val = ((val << 1) + v) % 5
            res[i] = (val == 0)
        return res
