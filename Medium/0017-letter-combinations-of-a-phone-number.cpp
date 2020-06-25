class Solution {
    static const string letters[10];
    
    void dfs(vector<string>& res, const string& digits, int pos, string& now) {
        if (pos == digits.size()) {
            res.push_back(now);
            return;
        }
        int digit = digits[pos] - '0';
        for (char ch : letters[digit - 2]) {
            now.push_back(ch);
            dfs(res, digits, pos + 1, now);
            now.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (!digits.empty()) {
            string tmp;
            dfs(res, digits, 0, tmp);
        }
        return res;
    }
};

const string Solution::letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
