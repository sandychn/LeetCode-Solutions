class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();

        sort(nums.begin(), nums.end());

        int ans = 0x3F3F3F3F;

        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue; // optimization, see problem #15
            int a = nums[i];
            int l = i + 1, r = N - 1;
            while (l < r) {
                if (l > i + 1 && nums[l - 1] == nums[l]) { // optimization, see problem #15
                    ++l;
                    continue;
                }
                if (r < N - 1 && nums[r] == nums[r + 1]) { // optimization, see problem #15
                    --r;
                    continue;
                }
                int b = nums[l], c = nums[r];
                int now = a + b + c;
                if (now > target) {
                    if (abs(ans - target) > abs(now - target)) ans = now;
                    --r;
                } else if (now < target) {
                    if (abs(ans - target) > abs(now - target)) ans = now;
                    ++l;
                } else {
                    return target;
                }
            }
        }

        return ans;
    }
};
