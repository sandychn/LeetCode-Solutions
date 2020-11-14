class Solution {
public:
    static constexpr int MAX_VALUE = 1000;
    static constexpr int INF = 0x3F3F3F3F;

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
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
};
