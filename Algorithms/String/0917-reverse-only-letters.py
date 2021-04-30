import collections

Info = collections.namedtuple("Info", ["index", "ch"])


class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        alpha = "".join(ch for ch in S if ch.isalpha())
        nonAlpha = [Info(i, ch) for i, ch in enumerate(S) if not ch.isalpha()][::-1]
        ans = []
        for ch in reversed(alpha):
            while nonAlpha and nonAlpha[-1].index == len(ans):
                ans.append(nonAlpha.pop().ch)
            ans.append(ch)
        while nonAlpha and nonAlpha[-1].index == len(ans):
            ans.append(nonAlpha.pop().ch)
        return "".join(ans)
