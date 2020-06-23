class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for (int val : arr) ++cnt[val];
        vector<pair<int, int>> v;
        for (auto p : cnt) v.emplace_back(p.second, p.first);
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first <= k) {
                ++ans;
                k -= v[i].first;
            } else {
                break;
            }
        }
        return cnt.size() - ans;
    }
};
