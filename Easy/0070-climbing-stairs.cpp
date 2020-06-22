class Solution {
public:
    int climbStairs(int n) {
        // n >= 1.
        int ans[2] = {2, 1}; // answer for n = 2, and n = 1
        for (int i = 3; i <= n; i++) {
            ans[i & 1] = ans[i & 1] + ans[(i & 1) ^ 1];
        }
        return ans[n & 1];
    }
};
