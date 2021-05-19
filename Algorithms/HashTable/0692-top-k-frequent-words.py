class WordFreq:
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq

    def __lt__(self, rhs):
        if self.freq != rhs.freq:
            return self.freq < rhs.freq
        return self.word >= rhs.word

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        freqs = [WordFreq(word, cnt) for word, cnt in collections.Counter(words).items()]
        freqs.sort(reverse=True)
        return [freq.word for freq in freqs[:k]]
