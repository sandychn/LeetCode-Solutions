from typing import List


class Solution:

    MAX_WEIGHT = 500

    def shipWithinDays(self, weights: List[int], D: int) -> int:
        low, high = 0, len(weights) * Solution.MAX_WEIGHT
        possible = self.possible
        while low < high:
            mid = low + (high - low) // 2
            if possible(weights, D, mid):
                high = mid
            else:
                low = mid + 1
        return high

    def possible(self, weights: List[int], D: int, capacity: int) -> bool:
        ship = 0
        current = 0
        for weight in weights:
            if current + weight > capacity:
                ship += 1
                if ship > D:
                    return False
                current = weight
                if current > capacity:
                    return False
            else:
                current += weight
        if current > 0:
            ship += 1
        return ship <= D
