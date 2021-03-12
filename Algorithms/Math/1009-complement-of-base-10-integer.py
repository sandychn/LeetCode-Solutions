class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        ret = i = 0
        while N:
            ret |= (((N & 1) ^ 1) << i)
            i += 1
            N >>= 1
        return ret
