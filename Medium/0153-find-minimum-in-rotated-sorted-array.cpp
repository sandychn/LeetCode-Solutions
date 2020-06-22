class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        int p = 0, q = 1;
        while (q) {
            if (p + q >= nums.size() || nums[p + q] < nums[p]) {
                q >>= 1;
            } else {
                p += q;
                q <<= 1;
            }
        }

        return nums[(p + 1) % nums.size()];
    }
};
