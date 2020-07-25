class Solution {
public:
    using LL = long long;

    bool split(const vector<int>& nums, int subArrayCount, LL subArrayMaxSum) {
        int cnt = 0;
        LL sum = 0;
        for (int num : nums) {
            if (sum + num > subArrayMaxSum) {
                ++cnt;
                sum = num;
                // if (num > subArrayMaxSum) return false;
            } else {
                sum += num;
            }
        }
        return sum <= subArrayMaxSum && ++cnt <= subArrayCount;
    }

    int splitArray(vector<int>& nums, int m) {
        LL sum = accumulate(nums.begin(), nums.end(), 0LL);
        LL left = *max_element(nums.begin(), nums.end());
        LL right = sum;
        while (left < right) {
            LL mid = left + (right - left) / 2;
            if (split(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
