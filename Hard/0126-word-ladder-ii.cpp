const int INF = 1 << 20;

class Solution {
private:    
    vector<string> words;
    vector<vector<int>> edges;

public:
    int getWordId(const string& word) {
        return lower_bound(words.begin(), words.end(), word) - words.begin();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        words = wordList;
        words.push_back(beginWord);
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        if (!binary_search(words.begin(), words.end(), endWord)) {
            return {};
        }
        edges.resize(words.size());

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (transformCheck(words[i], words[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int start = getWordId(beginWord);
        const int dest = getWordId(endWord);
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(words.size(), INF);
        q.push(vector<int>{start});
        cost[start] = 0;
        while (!q.empty()) {
            vector<int> now;
            now.swap(q.front());
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now) tmp.push_back(words[index]);
                res.push_back(move(tmp));
            } else {
                for (int i = 0, len = edges[last].size(); i < len; i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(move(tmp));
                    }
                }
            }
        }
        return res;
    }
    
    bool transformCheck(const string& str1, const string& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }
        int differences = 0;
        int n = str1.size();
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                if (++differences > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
