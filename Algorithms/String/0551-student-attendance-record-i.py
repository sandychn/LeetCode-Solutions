import re


class Solution:
    def checkRecord(self, s: str) -> bool:
        return re.search(r"A.*A|LLL", s) is None
