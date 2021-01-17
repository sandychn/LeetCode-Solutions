class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        first = coordinates[0]
        
        k_numerator = coordinates[1][1] - first[1]
        k_denominator = coordinates[1][0] - first[0]

        for x, y in coordinates:
            numerator = first[1] - y
            denominator = first[0] - x
            if k_numerator * denominator != k_denominator * numerator:
                return False

        return True
