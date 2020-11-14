class Solution {
public:
    static constexpr int MAX_VALUE = 1000;
    static constexpr int INF = 0x3F3F3F3F;

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        return solver2(arr1, arr2);
    }

    vector<int> solver1(vector<int>& arr1, vector<int>& arr2) {
        vector<int> id(MAX_VALUE + 5, INF);
        for (int i = 0, n = arr2.size(); i < n; i++) {
            id[arr2[i]] = i;
        }
        auto compare = [&id](int x, int y) {
            int id1 = id[x];
            int id2 = id[y];
            if (id1 == INF && id2 == INF) return x < y;
            return id1 < id2;
        };
        sort(arr1.begin(), arr1.end(), compare);
        return arr1;
    }

    vector<int> solver2(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(MAX_VALUE + 5);
        for (int value : arr1) ++cnt[value];

        vector<int> res;
        res.reserve(arr1.size());
        for (int value : arr2) {
            while (cnt[value] > 0) {
                --cnt[value];
                res.push_back(value);
            }
        }
        for (int i = 0; i <= MAX_VALUE; i++) {
            while (cnt[i] > 0) {
                --cnt[i];
                res.push_back(i);
            }
        }
        return res;
    }
};
