class Solution:
    def minInsertions(self, s: str) -> int:
        s = s.replace('))', ']')
        left = 0
        ans = 0
        for ch in s:
            if ch == ']':
                if left == 0:
                    ans += 1
                else:
                    left -= 1
            elif ch == ')':
                ans += 1
                if left == 0:
                    ans += 1
                else:
                    left -= 1
            else:               # s == '('
                left += 1
        if left:
            ans += left * 2
        return ans
