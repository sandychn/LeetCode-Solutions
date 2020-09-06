class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int num : nums) ++cnt[num];

        vector<pair<int, int>> v(cnt.begin(), cnt.end());

        using PII = pair<int, int>;

        partial_sort(v.begin(), v.begin() + k, v.end(), [](const PII& lhs, const PII& rhs) -> bool {
            return lhs.second > rhs.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(v[i].first);

        return res;
    }
};
