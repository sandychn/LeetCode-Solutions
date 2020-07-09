class Solution {  // DP+字符串哈希
public:
    static const uint64_t SEED = 131;

    uint64_t getHash(const string& s) {
        uint64_t h = 0;
        for (int i = 0, size = s.size(); i < size; i++) {
            h = h * SEED + s[i];
        }
        return h;
    }

    int respace(vector<string>& dictionary, string sentence) {
        const int N = sentence.size();

        unordered_set<uint64_t> dictHashcodes;
        for (const string& word : dictionary) {
            dictHashcodes.insert(getHash(word));
        }

        vector<int> dp(N + 1, 1 << 30);
        // dp[i] 表示匹配第i个字符之前的所有字符需要跳过的最少字符个数
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            uint64_t currentHash = 0;
            for (int j = i; j < N; j++) {
                currentHash = currentHash * SEED + sentence[j];
                if (dictHashcodes.count(currentHash)) {
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }

        return dp[N];
    }
};

class Trie {
public:
    Trie() {
        clear();
    }

    void clear() {
        tot = 0;
        tree[tot].init();
    }

    void insert(const string& s) {
        int now = 0;
        for (char ch : s) {
            int id = ch - 'a';
            if (tree[now].next[id] == -1) {
                tree[++tot].init();
                tree[now].next[id] = tot;
            }
            now = tree[now].next[id];
        }
        tree[now].finish = true;
    }

    struct TrieNode {
        int next[26];
        bool finish;

        void init() {
            memset(next, -1, sizeof(next));
            finish = false;
        }
    };
    TrieNode tree[150005];
    int tot;
};

class TrieSolution {  // DP+Trie
public:
    int respace(vector<string>& dictionary, string sentence) {
        if (sentence.empty()) return 0;
        const int N = sentence.size();

        Trie trie;
        vector<int> dp(N + 1, 1 << 30);
        // dp[i] 表示匹配第i个字符之前的所有字符需要跳过的最少字符个数

        for (int i = 0, size = dictionary.size(); i < size; i++) {
            trie.insert(dictionary[i]);
        }

        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            int now = 0;
            for (int j = i; j < N; j++) {
                int id = sentence[j] - 'a';
                if (trie.tree[now].next[id] == -1) break;
                now = trie.tree[now].next[id];
                if (trie.tree[now].finish) {
                    dp[j + 1] = min(dp[j + 1], dp[i]); // 匹配
                }
            }
            dp[i + 1] = min(dp[i + 1], dp[i] + 1); // 跳过
        }

        return dp[N];
    }
};
