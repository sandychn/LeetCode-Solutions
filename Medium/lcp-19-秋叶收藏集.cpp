class Solution {
public:
    int minimumOperations(string leaves) {
        const int INF = 0x3F3F3F3F;
        int n = leaves.size();
        int dp[2][3];

        memset(dp, 0x3F, sizeof(dp));
        dp[0][0] = (leaves[0] != 'r');
        
        for (int i = 1; i < n; i++) {
            char ch = leaves[i];
            int u = i & 1;
            int v = u ^ 1;
            dp[u][0] = dp[v][0] + (ch != 'r');
            dp[u][1] = min(dp[v][1], dp[v][0]) + (ch != 'y');
            dp[u][2] = min(dp[v][1], dp[v][2]) + (ch != 'r');
        }
        
        return dp[(n - 1) & 1][2];
    }
};
