class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        const int n = grid.size();
        const int m = grid[0].size();

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
                            ++res;
                        }
                    }
                }
            }
        }

        return res;
    }
};
