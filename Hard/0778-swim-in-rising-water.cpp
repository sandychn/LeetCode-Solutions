struct Node {
    pair<int, int> pos;
    int val;

    Node(const pair<int, int>& pos, int val): pos(pos), val(val) {}

    bool operator<(const Node& rhs) const {
        return val > rhs.val;
    }
};

class Solution {
public:
    static bool inRange(int val, int l, int r) {
        return l <= val && val <= r;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int currentTime = 0;
        const pair<int, int> start(0, 0);
        const pair<int, int> dest(n - 1, n - 1);
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        vector<vector<int>> visited(n, vector<int>(n));
        priority_queue<Node> heap;

        heap.emplace(start, grid[start.first][start.second]);
        visited[start.first][start.second] = true;

        while (!heap.empty()) {
            while (heap.top().val <= currentTime) {
                Node now = heap.top();
                heap.pop();
                if (now.pos == dest) return currentTime;
                for (int i = 0; i < 4; i++) {
                    int x = now.pos.first + dx[i];
                    int y = now.pos.second + dy[i];
                    if (inRange(x, 0, n - 1) && inRange(y, 0, n - 1) && !visited[x][y]) {
                        heap.emplace(make_pair(x, y), grid[x][y]);
                        visited[x][y] = true;
                    }
                }
            }
            ++currentTime;
        }

        return -1; // should not run here
    }
};
