class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};

        bool visit[105][105];
        memset(visit, 0, sizeof(visit));

        vector<vector<int>> res;
        res.reserve(R * C);
        queue<pair<int, int>> que;
        que.emplace(r0, c0);
        visit[r0][c0] = true;

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            res.push_back({x, y});
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (0 <= newX && newX < R && 0 <= newY && newY < C && !visit[newX][newY]) {
                    que.emplace(newX, newY);
                    visit[newX][newY] = true;
                }
            }
        }

        return res;
    }
};
