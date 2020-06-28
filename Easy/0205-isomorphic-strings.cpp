class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int N = s.size();
        char mp[CHAR_MAX] = {};
        bool mapped_chars[CHAR_MAX] = {};
        for (int i = 0; i < N; i++) {
            char a = s[i];
            char b = t[i];
            if (mp[a] == 0) {
                // No two characters may map to the same character
                if (mapped_chars[b]) return false;
                mp[a] = b;
                mapped_chars[b] = true;
            } else {
                if (b != mp[a]) return false;
            }
        }
        return true;
    }
};
