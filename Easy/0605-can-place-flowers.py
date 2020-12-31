# -*- coding:utf8 -*-

class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        res = 0
        length = len(flowerbed)
        for i in xrange(length):
            prev = (flowerbed[i - 1] if i > 0 else 0)
            after = (flowerbed[i + 1] if i + 1 < length else 0)
            if prev == after == flowerbed[i] == 0:
                res += 1
                flowerbed[i] = 1
        return n <= res
