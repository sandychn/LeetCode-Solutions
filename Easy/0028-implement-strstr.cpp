class Solution {
public:
    vector<int> calcNext(const string& s) {
        int len = s.size();
        if (len == 0) return vector<int>();
        vector<int> next(len);
        next[0] = -1;
        for (int i = 0, j = -1; i < len - 1; ) {
            if (j == -1 || s[i] == s[j]) {
                ++i, ++j, next[i] = j;
            } else {
                j = next[j];
            }
        }
        return next;
    }

    int kmp(const string& s, const string& pattern, const vector<int>& next) {
        int i = 0, j = 0;
        int n = s.size(), m = pattern.size();
        while (i < n && j < m) {
            if (j == -1 || s[i] == pattern[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        return j == m ? i - m : -1;
    }

    int strStr(string haystack, string needle) {
        return kmp(haystack, needle, calcNext(needle));
    }
};
