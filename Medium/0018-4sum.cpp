class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < N - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int a = nums[i];
            for (int j = i + 1; j < N - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                int b = nums[j];
                int l = j + 1, r = N - 1;
                while (l < r) {
                    if (l > j + 1 && nums[l - 1] == nums[l]) {
                        ++l;
                        continue;
                    }
                    if (r < N - 1 && nums[r] == nums[r + 1]) {
                        --r;
                        continue;
                    }
                    int c = nums[l], d = nums[r];
                    int sum = a + b + c + d;
                    if (sum > target) {
                        --r;
                    } else if (sum < target) {
                        ++l;
                    } else {
                        res.push_back({a, b, c, d});
                        ++l;
                    }
                }
            }
        }

        return res;
    }
};
