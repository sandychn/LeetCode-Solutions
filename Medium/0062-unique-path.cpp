namespace std {
    template<>
    struct hash<pair<int, int>>  {
        size_t operator()(const pair<int, int> &p) const {
            return p.first * 131 + p.second;
        }
    };
}

class Solution {
   public:
    int uniquePaths(int m, int n) {
        return helper(n + m - 2, n - 1);
    }

private:
    unordered_map<pair<int, int>, int> mp;
    int helper(int m, int n) {
        if (n == 0 || n == m) return 1;

        auto it = mp.find(make_pair(m, n));
        if (it == mp.end()) {
            return mp[make_pair(m, n)] = helper(m - 1, n - 1) + helper(m - 1, n);
        }
        return it->second;
    }
};

class DPSolution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for (int j = 0; j < n; j++) dp[j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < m; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];

        // vector<vector<int>> dp(m, vector<int>(n));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0 && j == 0)
        //             dp[i][j] = 1;
        //         else if (i == 0)
        //             dp[i][j] = dp[i][j - 1];
        //         else if (j == 0)
        //             dp[i][j] = dp[i - 1][j];
        //         else
        //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }
        // return dp[m - 1][n - 1];
    }
};
