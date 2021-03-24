import re


class Solution:

    pattern = re.compile(r"[+-]?(\d+\.\d*|\.?\d+)([eE][+-]?\d+)?")

    def isNumber(self, s: str) -> bool:
        return bool(Solution.pattern.fullmatch(s))
