class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int n = nums.size();
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == val) {
                swap(nums[i], nums[--last]);
            }
        }
        return last;
    }
};
