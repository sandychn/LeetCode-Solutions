class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = []
        now = 1
        for i in range(rowIndex + 1):
            ans.append(now)
            now = now * (rowIndex - i) // (i + 1)
        return ans
