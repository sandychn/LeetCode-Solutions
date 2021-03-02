class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        return sum(1 for x, y in zip(guess, answer) if x == y)
