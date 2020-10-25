class Solution {
public:
    static constexpr int MAX_VALUE = 100;

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> cnt(MAX_VALUE + 1);
        vector<int> res(n);

        for (int i = 0; i < n; i++) ++cnt[nums[i]];
        for (int i = 1; i <= MAX_VALUE; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) res[i] = nums[i] > 0 ? cnt[nums[i] - 1] : 0;

        return res;
    }
};
