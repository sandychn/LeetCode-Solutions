#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::fill_n;

class Solution { // Space optimized
public:
    bool isMatch(string s, string p) {
        const int N = s.size();
        const int M = p.size();

        // due to the bad performance of vector<bool>,
        // use vector<char> instead
        vector<char> dp[2];
        fill_n(dp, 2, vector<char>(M + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= M; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i <= N; i++) {
            char a = s[i - 1];
            dp[i & 1][0] = 0;
            for (int j = 1; j <= M; j++) {
                char b = p[j - 1];
                if (b == '*') {
                    dp[i & 1][j] = dp[i & 1][j - 1] || dp[(~i) & 1][j];
                } else if (b == '?' || a == b) {
                    dp[i & 1][j] = dp[(~i) & 1][j - 1];
                } else {
                    dp[i & 1][j] = 0;
                }
            }
        }

        return static_cast<bool>(dp[N & 1][M]);
    }
};

class DPSolution {
public:
    bool isMatch(string s, string p) {
        const int N = s.size();
        const int M = p.size();

        // due to the bad performance of vector<bool>,
        // use vector<char> instead
        vector<vector<char>> dp(N + 1, vector<char>(M + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= M; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = 1;
            } else {
                break;
            }
        }

        for (int i = 1; i <= N; i++) {
            char a = s[i - 1];
            for (int j = 1; j <= M; j++) {
                char b = p[j - 1];
                if (b == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (b == '?' || a == b) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // otherwise, dp[i][j] = 0
            }
        }

        return static_cast<bool>(dp[N][M]);
    }
};
