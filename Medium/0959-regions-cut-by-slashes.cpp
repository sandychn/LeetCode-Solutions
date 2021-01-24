class Solution {
public:
    static constexpr int N = 30 * 3 + 5;
    bool mp[N][N];
    bool visited[N][N];
    int row;
    int col;

    void dfs(int x, int y)
    {
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < row * 3 && 0 <= ny && ny < col * 3 && !visited[nx][ny] && !mp[nx][ny])
            {
                visited[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        row = col = grid.size();
        memset(mp, 0, sizeof(mp));
        memset(visited, 0, sizeof(visited));
        for (int i = 0, mpi = 0; i < row; i++, mpi += 3)
        {
            int len = grid[i].size();
            for (int j = 0, mpj = 0; j < len; j++, mpj += 3)
            {
                char ch = grid[i][j];
                if (ch == '\\')
                {
                    mp[mpi][mpj] = mp[mpi + 1][mpj + 1] = mp[mpi + 2][mpj + 2] = true;
                }
                else if (ch == '/')
                {
                    mp[mpi][mpj + 2] = mp[mpi + 1][mpj + 1] = mp[mpi + 2][mpj] = true;
                }
            }
        }
        int parts = 0;
        for (int i = 0; i < 3 * row; i++)
        {
            for (int j = 0; j < 3 * col; j++)
            {
                if (!visited[i][j] && !mp[i][j])
                {
                    dfs(i, j);
                    ++parts;
                }
            }
        }
        return parts;
    }
};
