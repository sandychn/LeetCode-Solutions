class Solution { // TwoPointers, O(N)
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int N = nums.size();

        int64_t sum = 0;
        int l = 0, r = 0;
        int ans = N + 1;
        while (r < N) {
            sum += nums[r];
            while (sum >= s) {  // there's no need to check l<=r because s>0.
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
            ++r;
        }
        return ans == N + 1 ? 0 : ans;
    }
};

class BinarySearchSolution { // O(N*logN)
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int N = nums.size();

        vector<int> sums(N + 1);
        partial_sum(nums.begin(), nums.end(), sums.begin() + 1);
        int ans = N + 1;
        for (int right = 1; right <= N; right++) {
            // rightSum - leftSum >= s
            // leftSum <= rightSum - s
            int left = upper_bound(sums.begin(), sums.begin() + right, sums[right] - s) - sums.begin() - 1;
            if (left >= 0) {
                ans = min(ans, right - left);
            }
        }
        return ans == N + 1 ? 0 : ans;
    }
};
