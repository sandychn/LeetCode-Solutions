class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        i, length = 0, len(data)
        while i < length:
            ones = self.getOnes(data[i])
            if ones == 0:
                i += 1
            elif 1 < ones <= 4:
                i += 1
                ones -= 1
                while ones:
                    if i >= length or data[i] >> 6 != 0b10:
                        return False
                    ones -= 1
                    i += 1
            else:
                return False
        return True


    def getOnes(self, value: int) -> int:
        x = 1 << 7
        ones = 0
        while value & x:
            ones += 1
            x >>= 1
        return ones
