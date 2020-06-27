class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] <= 0) nums[i] = INT_MAX;
        }
        for (int i = 0; i < N; i++) {
            int x = abs(nums[i]) - 1;
            if (x >= N) continue;
            nums[x] = -abs(nums[x]);
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return N + 1;
    }
};

class OfficalSolution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
