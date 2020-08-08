class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, f = 1;
        for (int i = int(s.size()) - 1; i >= 0; i--) {
            res += f * (s[i] - 'A' + 1);
            if (i) f *= 26; // avoid signed integer overflow
        }
        return res;
    }
};
