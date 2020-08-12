class Solution {
public:
    bool solve(string& s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] - 'a' == s[i - 1] - 'A' || s[i] - 'A' == s[i - 1] - 'a') {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i - 1);
                return true;
            }
        }
        return false;
    }
    
    string makeGood(string s) {
        while (solve(s));
        return s;
    }
};
