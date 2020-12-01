class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = lower_bound(begin(nums), end(nums), target) - begin(nums);
        if (low >= n || nums[low] != target) {
            return {-1, -1};
        }
        int up = upper_bound(begin(nums), end(nums), target) - begin(nums);
        return {low, up - 1};
    }
};
