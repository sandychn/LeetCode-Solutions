class Solution {
public:
    int search(vector<int>& nums, int target) {
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

        // nums[p] is the biggest value in nums.
        int l, r;
        if (target >= nums[0]) { // the target's index is in [0, p].
            l = -1;
            r = p + 1;
        } else { // the target's index is in [p+1, nums.size()-1].
            l = p;
            r = nums.size();
        }
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l >= 0 && nums[l] == target ? l : -1;
    }
};

class AnotherSolution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) { // [left, mid] is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // [mid, right] is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
