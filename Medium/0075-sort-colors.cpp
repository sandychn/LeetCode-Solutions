class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroPos = -1, twoPos = nums.size();
        for (int i = 0; i < twoPos; ) {
            if (nums[i] == 0) {
                swap(nums[i++], nums[++zeroPos]);
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[--twoPos]);
            }
        }
    }
};
