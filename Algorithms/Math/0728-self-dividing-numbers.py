class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        return [number for number in range(left, right + 1) if self.isSelfDividing(number)]

    def isSelfDividing(self, number: int) -> bool:
        temp = number
        while temp:
            digit = temp % 10
            if digit == 0 or number % digit != 0:
                return False
            temp //= 10
        return True
