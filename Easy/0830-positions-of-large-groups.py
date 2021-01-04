# -*- coding:utf8 -*-

class Solution(object):
    def largeGroupPositions(self, s):
        """
        :type s: str
        :rtype: List[List[int]]
        """
        n = len(s)
        prev = None
        cnt = 0
        first = -1
        res = []
        for idx, ch in enumerate(s):
            if ch == prev:
                cnt += 1
                if idx + 1 == n and cnt > 2:
                    res.append([first, idx])
            else:
                if cnt > 2:
                    res.append([first, idx - 1])
                cnt = 1
                first = idx
            prev = ch
        return res
