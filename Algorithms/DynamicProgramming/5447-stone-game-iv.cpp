#include <vector>

using std::vector;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            if (dp[i] == 0) {
                for (int j = 1; i + j * j <= n; j++) {
                    dp[i + j * j] = 1;
                }
            }
        }
        return dp[n];
    }
};

class RecursiveSolution {
    bool winnerSquareGame(int n) {
        vector<int> states(n + 1, -1);
        return f(states, n);
    }

    bool f(vector<int>& states, int n) {
        if (n == 0) return false;
        if (states[n] != -1) return states[n];

        for (int i = 1; i * i <= n; i++) {
            if (!f(states, n - i * i)) return states[n] = 1;
        }

        return states[n] = 0;
    }
};
