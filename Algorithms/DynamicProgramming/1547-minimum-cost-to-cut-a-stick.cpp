class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> parts;
        int last = 0;
        for (int x : cuts) parts.push_back(x - last), last = x;
        parts.push_back(n - last);
        
        return solve(parts);
    }
    
    int solve(vector<int> parts) {
        int n = parts.size();
        int sum[105];
        int dp[105][105];

        sum[0] = 0;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + parts[i - 1];
        
        memset(dp, 0x3F, sizeof(dp));
        for (int i = 1; i <= n; i++) dp[i][i] = 0;

        for (int len = 2; len <= n; len++) {
            for (int r = len; r <= n; r++) {
                int l = r - len + 1;
                for (int k = l; k < r; k++) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
                    
                }
            }
        }
        return dp[1][n];

        // 下方每次找两个最短的合并的贪心算法并非最优
        // 错误样例:
        // 19
        // [5, 9, 13, 17]
        // 
        // int cost = 0;
        // while (parts.size() != 1) {
        //     int len = parts.size();
        //     int mergePos = 1;
        //     for (int i = 1; i < len; i++) {
        //         if (parts[i] + parts[i - 1] < parts[mergePos] + parts[mergePos - 1]) {
        //             mergePos = i;
        //         }
        //     }
        //     int now = parts[mergePos] + parts[mergePos - 1];
        //     cost += now;
        //     parts.erase(parts.begin() + mergePos);
        //     parts[mergePos - 1] = now;
        // }
        // return cost;
    }
};
