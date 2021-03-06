DIR_TUPLE = ((0, 1), (0, -1), (1, 0), (-1, 0))

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.board = board
        self.m = len(board)
        self.n = len(board[0])
        return [word for word in words if self.find(word)]

    def dfs(self, word: str, matched: int, curX: int, curY: int) -> None:
        if self.board[curX][curY] == word[matched]:
            matched += 1
            if matched == len(word):
                return True
        else:
            return False
        ch = self.board[curX][curY]
        self.board[curX][curY] = None
        res = False
        for dx, dy in DIR_TUPLE:
            newX, newY = curX + dx, curY + dy
            if 0 <= newX < self.m and 0 <= newY < self.n and self.dfs(word, matched, newX, newY):
                res = True
                break
        self.board[curX][curY] = ch
        return res

    def find(self, word: str) -> bool:
        return any(self.dfs(word, 0, i, j) for j in range(self.n) for i in range(self.m))
