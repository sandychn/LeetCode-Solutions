#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int N = s1.size();
        const int M = s2.size();

        if (N + M != s3.size()) return false;

        vector<vector<int>> dp(N + 1, vector<int>(M + 1));
        dp[0][0] = 1;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if (i < N && s3[i + j] == s1[i]) {
                    dp[i + 1][j] |= dp[i][j];
                }
                if (j < M && s3[i + j] == s2[j]) {
                    dp[i][j + 1] |= dp[i][j];
                }
            }
        }

        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j <= M; j++) {
        //         if (i > 0 && s3[i + j - 1] == s1[i - 1]) {
        //             dp[i][j] |= dp[i - 1][j];
        //         }
        //         if (j > 0 && s3[i + j - 1] == s2[j - 1]) {
        //             dp[i][j] |= dp[i][j - 1];
        //         }
        //     }
        // }

        return dp[N][M];
    }
};
