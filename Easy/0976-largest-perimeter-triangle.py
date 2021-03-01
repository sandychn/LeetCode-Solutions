class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        sides = sorted(A)
        for i in range(len(sides) - 1, 1, -1):
            if sides[i] < sides[i - 1] + sides[i - 2]:
                return sides[i] + sides[i - 1] + sides[i - 2]
        return 0
