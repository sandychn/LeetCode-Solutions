SEED = 131
HASH_VALUE_MAX = (1 << 32) - 1

class Solution:
    def solve(self, start: int, pos: int, fwdHash: int, bwdHash: int, times: int, memory: Dict[Tuple[int, int], List[List[str]]]):
        if start >= len(self.s):
            return []
        m = memory.get((start, pos))
        if m is not None:
            return m
        if pos == len(self.s):
            res = memory[(start, pos)] = [[self.s[start:pos]]] if fwdHash == bwdHash else []
            return res
        ch = self.s[pos]
        fwdHash = (fwdHash * SEED + ord(ch)) & HASH_VALUE_MAX
        bwdHash = (bwdHash + ord(ch) * times) & HASH_VALUE_MAX
        times = (times * SEED) & HASH_VALUE_MAX
        res = self.solve(start, pos + 1, fwdHash, bwdHash, times, memory)
        if fwdHash == bwdHash:
            res.extend([self.s[start:pos + 1]] + x for x in self.solve(pos + 1, pos + 1, 0, 0, 1, memory))
        memory[(start, pos)] = res
        return res

    def partition(self, s: str) -> List[List[str]]:
        self.s = s
        return self.solve(0, 0, 0, 0, 1, {})
