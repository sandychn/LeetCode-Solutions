# -*- coding: utf8 -*-

class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        def updateAnswer(res, x, y):
            if x is None:
                return
            if x == y - 1:
                ans.append(str(x))
            else:
                ans.append("{}->{}".format(x, y - 1))

        ans = []
        start = expected = None
        for val in nums:
            if val == expected:
                expected += 1
            else:
                updateAnswer(ans, start, expected)
                start, expected = val, val + 1
        updateAnswer(ans, start, expected)
        return ans
