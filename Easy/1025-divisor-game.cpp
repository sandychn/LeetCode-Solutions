class Solution {
public:
    bool divisorGame(int N) {
        // return N & 1 == 0;

        vector<int> dp(N + 5);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0 && dp[i - j] == 0) {
                    dp[i] = 1;
                }
            }
        }

        return dp[N];
    }
}; 
