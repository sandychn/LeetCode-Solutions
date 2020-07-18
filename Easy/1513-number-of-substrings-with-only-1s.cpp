class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        const int N = s.size();

        if (N == 0) return 0;
        
        int ans = 0, cnt = (s[0] == '1');
        for (int i = 1; i < N; i++) {
            if (s[i] == '1') {
                ++cnt;
            } else {
                ans = (ans + 1LL * cnt * (cnt + 1) / 2) % MOD;
                cnt = 0;
            }
        }
        
        if (cnt) ans = (ans + 1LL * cnt * (cnt + 1) / 2) % MOD;

        return ans;
    }
};
