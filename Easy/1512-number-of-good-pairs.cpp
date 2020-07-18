class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[100] = {};
        int ans = 0;
        for (int num : nums) {
            ans += cnt[num - 1];
            ++cnt[num - 1];
        }
        return ans;
    }
};
