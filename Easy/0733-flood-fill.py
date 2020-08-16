class Solution:
    def dfs(self, x, y):
        original_color = self.image[x][y]
        self.image[x][y] = self.newColor
        for dx, dy in zip((-1, 1, 0, 0), (0, 0, -1, 1)):
            newX, newY = x + dx, y + dy
            if 0 <= newX < self.n and 0 <= newY < self.m and self.image[newX][newY] == original_color:
                self.dfs(newX, newY)

    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        if image[sr][sc] == newColor:
            return image
        self.n, self.m = len(image), len(image[0])
        self.newColor = newColor
        self.image = image
        self.dfs(sr, sc)
        return image
