from typing import List

import collections
import re


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words_generator = (word.lower() for word in re.split("[!?',;. ]", paragraph) if word)
        banned_set = set(banned)
        counter = collections.Counter(word for word in words_generator if word not in banned_set)
        maxCount, res = 0, None
        for word, count in counter.items():
            if count > maxCount:
                maxCount, res = count, word
        return res
