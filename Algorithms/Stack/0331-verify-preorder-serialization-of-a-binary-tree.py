class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        need = 1
        i, length = 0, len(preorder)
        while i < length and need > 0:
            if preorder[i] == ",":
                i += 1
            elif preorder[i] == "#":
                need -= 1
                i += 1
            else:
                need += 1  # need = need - 1 + 2
                while i < length and preorder[i] not in ",#":
                    i += 1
        return need == 0 and i == length
