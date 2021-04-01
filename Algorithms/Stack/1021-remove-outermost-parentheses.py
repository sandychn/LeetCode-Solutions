class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        ans = []
        depth = 0
        for ch in S:
            if ch == "(":
                if depth > 0:
                    ans.append("(")
                depth += 1
            else:
                depth -= 1
                if depth > 0:
                    ans.append(")")
        return "".join(ans)
