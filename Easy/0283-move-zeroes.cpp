class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p = 0, q = 0;
        int cnt = 0;
        while (q < n) {
            if (nums[q] == 0) {
                ++cnt;
            } else {
                nums[p++] = nums[q];
            }
            ++q;
        }
        while (p < n) nums[p++] = 0;
    }
};
