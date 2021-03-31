class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace("-", "")
        first = (len(S) % K) if (len(S) % K) else K
        res = []
        res.append(S[:first])
        cur = first
        while cur < len(S):
            res.append(S[cur:cur + K])
            cur += K
        return "-".join(map(str.upper, res))
