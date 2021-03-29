class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnter = collections.Counter(magazine)
        for ch in ransomNote:
            if ch not in cnter:
                return False
            cnter[ch] -= 1
            if cnter[ch] == 0:
                cnter.pop(ch)
        return True
