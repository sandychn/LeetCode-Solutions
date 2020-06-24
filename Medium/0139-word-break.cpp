// My Solution, 4 ms, 7.7 MB
// 数据不强，复杂度应该不比 OfficalSolution 优秀
class Solution {
    string s;
    bool* failed = nullptr;

    bool dfs(int pos, vector<string>& wordDict) {
        if (pos == s.size()) return true;
        if (failed[pos]) return false;
        int charsRemaining = static_cast<int>(s.size()) - pos;
        for (const string& word : wordDict) {
            if (word.size() > charsRemaining) break;
            const char* s1 = s.c_str() + pos;
            const char* s2 = word.c_str();
            const int n = word.size();
            if (strncmp(s1, s2, n) == 0 && dfs(pos + n, wordDict)) {
                return true;
            }
        }
        failed[pos] = true;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end(), [](const string& s1, const string& s2) {
            return s1.size() < s2.size();
        });
        this->s = s;
        failed = new bool[s.size()]();
        bool res = dfs(0, wordDict);
        delete[] failed;
        failed = nullptr;
        return res;
    }
};

// 24 ms, 13.3 MB
class OfficalSolution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.size();

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unique_ptr<bool[]> dp(new bool[N + 1]());
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                    break;   
                }
            }
        }
        return dp[N];
    }
};
