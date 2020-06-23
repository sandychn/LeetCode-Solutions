class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        // for (int i = 2; i < N; i++) 的写法取 l = 0, r = i - 1 做双指针
        // 会在 [-2, 0, 1, 1, 2] 这样的数据上出现 bug, 因为用
        // if (i > 2 && nums[i - 1] == nums[i]) continue;
        // 这种判断会漏解 [-2, 1, 1], 即 nums[?], nums[i - 1], nums[i] 这样的解
        // 而使用 for (int i = 0; i < N - 2; i++)
        // 配合 if (i > 0 && nums[i - 1] == nums[i]) continue;
        // 这种写法不会漏解, 因为, 若存在 nums[?], nums[i - 1], nums[i] 这样的解
        // 则前面的循环中存在一个 i = x,
        // 已经处理过这样的解了 nums[x], nums[l], nums[r] (其中 l + 1 == r)
        for (int i = 0; i < N - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int a = nums[i];
            int l = i + 1, r = N - 1;
            while (l < r) {
                int b = nums[l], c = nums[r];
                if (l > i + 1 && b == nums[l - 1]) {
                    ++l;
                    continue;
                }
                if (r < N - 1 && c == nums[r + 1]) {
                    --r;
                    continue;
                }
                if (a + b + c > 0) {
                    --r;
                } else if (a + b + c < 0) {
                    ++l;
                } else {
                    res.push_back({a, b, c});
                    ++l;
                }
            }
        }

        return res;
    }
};
