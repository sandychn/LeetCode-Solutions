class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return process(S) == process(T);
    }

    string process(const string& s) {
        string res;
        for (char ch : s) {
            if (ch == '#') {
                if (!res.empty()) res.pop_back();
            } else {
                res += ch;
            }
        }
        return res;
    }
};
