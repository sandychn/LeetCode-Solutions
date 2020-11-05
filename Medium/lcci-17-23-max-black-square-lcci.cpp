class Solution {
public:
    static constexpr int N = 205;
    int sum[N][N];

    int get(int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return 0;
        return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    }

    vector<int> findSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i <= n; i++) sum[i][0] = sum[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        for (int size = n; size >= 1; size--) {
            for (int r = 1; r <= n - size + 1; r++) {
                for (int c = 1; c <= n - size + 1; c++) {
                    int x = r + size - 1;
                    int y = c + size - 1;
                    int p = get(r, c, x, y);
                    int q = get(r + 1, c + 1, x - 1, y - 1);
                    if (p == q) {
                        return {r - 1, c - 1, size};
                    }
                }
            }
        }

        return {};
    }

};
