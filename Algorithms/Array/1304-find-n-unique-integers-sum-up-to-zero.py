class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n & 1:
            return [*range(-(n // 2), 0), *range(0, n // 2 + 1)]
        return [*range(-(n // 2), 0), *range(1, n // 2 + 1)]
