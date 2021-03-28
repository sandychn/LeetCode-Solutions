class Solution:
    def reverseBits(self, n: int) -> int:
        r = 0
        for _ in range(32):
            r = (r << 1) | (n & 1)
            n >>= 1
        return r
        # return int("{:032b}".format(n)[::-1], 2)
