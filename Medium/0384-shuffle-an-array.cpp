class Solution {
public:
    vector<int> original;
    vector<int> nums;

    Solution(vector<int>& nums): original(nums), nums(nums) {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int pos = rand() % (i + 1);
            swap(nums[i], nums[pos]);
        }
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
