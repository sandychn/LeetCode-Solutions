class Solution {
public:
    string frequencySort(string s) {
        int cnt[CHAR_MAX] = {};
        for (char ch : s) ++cnt[ch];
        priority_queue<pair<int, char>> heap;
        for (int i = 0; i < CHAR_MAX; i++) {
            if (cnt[i]) {
                heap.emplace(cnt[i], static_cast<char>(i));
            }
        }
        string res;
        while (!heap.empty()) {
            auto now = heap.top();
            heap.pop();
            while (now.first--) {
                res += now.second;
            }
        }
        return res;
    }
};
