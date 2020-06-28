class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set('aeiouAEIOU')
        res = [None] * len(s)
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and s[i] not in vowels:
                res[i] = s[i]
                i += 1
            while i < j and s[j] not in vowels:
                res[j] = s[j]
                j -= 1
            if i >= j: break
            res[i], res[j] = s[j], s[i]
            i += 1
            j -= 1
        if i == j:
            res[i] = s[i]
        return ''.join(res)
