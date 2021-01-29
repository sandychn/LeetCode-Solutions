struct Node {
    pair<int, int> pos;
    int cost;
    Node(const pair<int, int>& pos, int cost): pos(pos), cost(cost) {}
    bool operator<(const Node& rhs) const { return cost > rhs.cost; }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> costs(row, vector<int>(col, INT_MAX));
        priority_queue<Node> q;
        q.emplace(make_pair(0, 0), 0);
        costs[0][0] = 0;

        const pair<int, int> dest(row - 1, col - 1);

        while (!q.empty()) {
            Node now = q.top();
            q.pop();
            if (now.pos == dest) break;
            for (int k = 0; k < 4; k++) {
                int x = now.pos.first + dx[k];
                int y = now.pos.second + dy[k];
                if (0 <= x && x < row && 0 <= y && y < col) {
                    int cost = max(now.cost, abs(heights[now.pos.first][now.pos.second] - heights[x][y]));
                    if (cost < costs[x][y]) {
                        costs[x][y] = cost;
                        q.emplace(make_pair(x, y), cost);
                    }
                }
            }
        }

        return costs[dest.first][dest.second];
    }
};
