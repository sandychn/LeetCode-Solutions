# -*- coding:utf8 -*-

class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        mapping = {}
        characters_mapped = set()
        for c1, c2 in zip(s, t):
            if c1 in mapping:
                if c2 != mapping[c1]:
                    return False
            else:
                if c2 in characters_mapped:
                    return False
                characters_mapped.add(c2)
                mapping[c1] = c2
        return True
