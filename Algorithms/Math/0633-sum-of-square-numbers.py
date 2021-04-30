class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        while a * a <= c:
            b = math.sqrt(c - a * a)
            if abs(b - int(b)) <= 1e-6:
                return True
            a += 1
        return False
