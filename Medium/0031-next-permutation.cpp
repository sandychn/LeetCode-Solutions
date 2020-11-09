class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int size = nums.size();
        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        if (i >= 0) {
            int j = size - 1;
            while (j >= 0 && nums[i] >= nums[j]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};


// nums[i] < nums[i+1]
// nums[i+1] >= nums[i + 2] >= ... >= nums[size-1]
// nums[i] < nums[j]
// nums[i] >= nums[j+1, j+2, ..., size-1]
