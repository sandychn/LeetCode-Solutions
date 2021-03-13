class Solution:
    def longestWord(self, words: List[str]) -> str:
        words_set = set(words)
        ans = ""
        for word in words:
            if not self.checkPrefix(word, words_set):
                continue
            if len(word) > len(ans) or (len(word) == len(ans) and word < ans):
                ans = word
        return ans
    
    def checkPrefix(self, word: str, words_set: Set[str]) -> bool:
        return all(word[:i] in words_set for i in range(len(word) - 1, 0, -1))
