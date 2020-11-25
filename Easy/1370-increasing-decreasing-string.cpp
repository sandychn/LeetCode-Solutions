class Solution {
public:
    string sortString(string s) {
        int cnt[26] = {};
        for_each(begin(s), end(s), [&cnt](char ch) {
            ++cnt[ch - 'a'];
        });

        string res;
        while (res.size() < s.size()) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i]) {
                    --cnt[i];
                    res += static_cast<char>(i + 'a');
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (cnt[i]) {
                    --cnt[i];
                    res += static_cast<char>(i + 'a');
                }
            }
        }

        return res;
    }
};
