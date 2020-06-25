class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> v(numRows);
        int nowRow = 0, delta = 1;
        for (char ch : s) {
            v[nowRow] += ch;
            nowRow += delta;
            if (nowRow == 0 || nowRow + 1 == numRows) delta *= -1;
        }
        string res;
        for (const string& str : v) res += str;
        return res;
    }
};

class OfficalSolution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        const int N = s.size();
        string res;
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < N; j += cycleLen) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < N)
                    res += s[j + cycleLen - i];
            }
        }
        return res;
    }
};
