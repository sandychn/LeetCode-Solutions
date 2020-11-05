class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) return 0;
        int endWordIndex = it - wordList.begin();
        
        int n = wordList.size();
        edge.resize(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(wordList[i], wordList[j])) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }

        queue<pair<int, int>> q;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (check(beginWord, wordList[i])) {
                q.emplace(i, 1);
                visit[i] = true;
            }
        }

        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            if (now.first == endWordIndex) return now.second + 1;

            for (int to : edge[now.first]) {
                if (!visit[to]) {
                    q.emplace(to, now.second + 1);
                    visit[to] = true;
                }
            }
        }

        return 0;
    }

    bool check(const string& a, const string& b) {
        int diff = 0;
        if (a.size() != b.size()) return false;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && ++diff > 1) return false;
        }
        return true;
    }

    vector<vector<int>> edge;
};
