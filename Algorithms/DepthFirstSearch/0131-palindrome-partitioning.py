SEED = 131
HASH_VALUE_MAX = (1 << 32) - 1

class Solution:
    def solve(self, s: str, start: int, pos: int, fwdHash: int, bwdHash: int, times: int, memory: dict):
        if start >= len(s):
            return []
        m = memory.get((start, pos))
        if m is not None:
            return m
        if pos == len(s):
            res = memory[(start, pos)] = [[s[start:pos]]] if fwdHash == bwdHash else []
            return res
        ch = s[pos]
        fwdHash = (fwdHash * SEED + ord(ch)) & HASH_VALUE_MAX
        bwdHash = (bwdHash + ord(ch) * times) & HASH_VALUE_MAX
        times = (times * SEED) & HASH_VALUE_MAX
        res = self.solve(s, start, pos + 1, fwdHash, bwdHash, times, memory)
        if fwdHash == bwdHash:
            res.extend([s[start:pos + 1]] + x for x in self.solve(s, pos + 1, pos + 1, 0, 0, 1, memory))
        memory[(start, pos)] = res
        return res

    def partition(self, s: str) -> List[List[str]]:
        return self.solve(s, 0, 0, 0, 0, 1, {})
