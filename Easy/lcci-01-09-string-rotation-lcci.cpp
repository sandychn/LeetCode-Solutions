class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s2.empty() ? s1.empty() : (s1 + s1).find(s2) != string::npos;
    }
};
