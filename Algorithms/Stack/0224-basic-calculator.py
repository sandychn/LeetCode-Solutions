class Solution:
    def calculate(self, s: str) -> int:
        stack = [1]
        sign = 1
        res = 0
        i = 0
        while i < len(s):
            if s[i].isdigit():
                val = 0
                while i < len(s) and s[i].isdigit():
                    val = val * 10 + int(s[i])
                    i += 1
                res += val * sign
            else:
                if s[i] == "+":
                    sign = stack[-1]
                elif s[i] == "-":
                    sign = -stack[-1]
                elif s[i] == "(":
                    stack.append(sign)
                elif s[i] == ")":
                    stack.pop()
                elif s[i] == " ":
                    pass
                else:
                    raise ValueError("Unexpected character")
                i += 1
        return res
