class Solution { // 空间压缩
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        const int N = obstacleGrid.size();
        const int M = obstacleGrid[0].size();
        
        vector<int> dp(M);
        dp[0] = (obstacleGrid[0][0] == 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else {
                    if (i > 0 && j > 0) {
                        dp[j] += dp[j - 1];
                    } else if (j > 0) {
                        dp[j] = dp[j - 1];
                    }
                    // 上面两个 if 亦可像题解中一样直接写
                    // if (j > 0) dp[j] += dp[j - 1];
                }
            }
        }

        return dp[M - 1];
    }
};

class OriginalSolution { // 未空间压缩原版DP解法
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        const int N = obstacleGrid.size();
        const int M = obstacleGrid[0].size();
        
        vector<vector<int>> dp(N, vector<int>(M));
        dp[0][0] = (obstacleGrid[0][0] == 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[N - 1][M - 1];
    }
};
