class Solution:
    MOD = 1000000007

    def numPrimeArrangements(self, n: int) -> int:
        primeCount = sum(1 for i in range(2, n + 1) if all(i % j != 0 for j in range(2, int(math.sqrt(i) + 1))))
        return self.factorial(primeCount) * self.factorial(n - primeCount) % Solution.MOD

    def factorial(self, number: int) -> int:
        res = 1
        while number > 1:
            res = res * number % Solution.MOD
            number -= 1
        return res
