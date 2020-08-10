class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        hasLeadingZeros = lambda x: x != str(int(x))
        
        res = []
        for i in range(1, 4):
            for j in range(1, 4):
                for k in range(1, 4):
                    if i + j + k >= len(s): break
                    a, b, c, d = s[0:i], s[i:i+j], s[i+j:i+j+k], s[i+j+k:]
                    if any((hasLeadingZeros(x) for x in (a, b, c, d))): continue
                    if all((0 <= x <= 255 for x in map(int, (a, b, c, d)))):
                        res.append('.'.join((a, b, c, d)))
        return res
