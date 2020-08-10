class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int cnt[2] = {};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = s[i] - '0';
            if (i > 0 && s[i - 1] != s[i]) {
                cnt[x] = 1;
            } else {
                ++cnt[x];
            }
            if (cnt[x ^ 1] >= cnt[x]) ++ans;
        }
        return ans;
    }
};
