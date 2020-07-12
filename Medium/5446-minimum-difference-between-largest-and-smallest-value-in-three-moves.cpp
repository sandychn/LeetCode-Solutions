class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 3) return 0;

        const int N = nums.size();
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            res = min(res, nums[N - 4 + i] - nums[i]);
        }
        return res;
    }
};
