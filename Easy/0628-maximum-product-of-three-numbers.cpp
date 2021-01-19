class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        partial_sort(nums.begin(), nums.begin() + 2, nums.end());
        // nums[0] <= nums[1] <= min(nums[2:])
        vector<int> v = {nums[0], nums[1]};
        partial_sort(nums.begin(), nums.begin() + 3, nums.end(), greater<int>());
        // nums[0] >= nums[1] >= nums[2] >= max(nums[3:])
        return max(v[0] * v[1] * nums[0], nums[2] * nums[1] * nums[0]);
    }
};
