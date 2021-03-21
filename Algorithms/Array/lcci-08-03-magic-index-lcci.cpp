class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        // int n = nums.size();
        // return solve1(nums, 0, n - 1);
        return solve2(nums);
    }

    int solve2(const vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == i) return i;
            i = max(i + 1, nums[i]);
        }
        return -1;
    }

    int solve1(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        int res = solve1(nums, left, mid - 1);
        if (res != -1) {
            return res;
        }
        if (nums[mid] == mid) {
            return mid;
        }
        return solve1(nums, mid + 1, right);
    }
};
