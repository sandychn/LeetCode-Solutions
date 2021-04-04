class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        counter = collections.Counter(answers)
        return sum((rabbitCount + answer) // (answer + 1) * (answer + 1) for answer, rabbitCount in counter.items())
