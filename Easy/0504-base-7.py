class Solution:
    def convertToBase7(self, num: int) -> str:
        res = []
        neg = (num < 0)
        num = abs(num)
        while num:
            res.append(num % 7)
            num //= 7
        if not res:
            res = [0]
        return ("-" if neg else "") + "".join(map(str, reversed(res)))
