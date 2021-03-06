# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def helper(self, bound: int) -> int:
        # return random number in [1, bound], bound must <= 7
        if bound <= 7:
            while True:
                if (x := rand7()) <= bound:
                    return x

    def rand10(self) -> int:
        x = self.helper(5)       # reject probability = 2/7, expected call count = (1/(1-2/7)) = 1.40
        y = self.helper(6) & 1   # reject probability = 1/7, expected call count = (1/(1-1/7)) = 1.17
        return x * 2 - y
