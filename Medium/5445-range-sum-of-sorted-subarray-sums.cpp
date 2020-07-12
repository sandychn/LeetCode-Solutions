const int MOD = 1e9 + 7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for (int i = 0; i < n; i++) {
            int total = 0;
            for (int j = i; j < n; j++) {
                total = (total + nums[j]) % MOD;
                sum.push_back(total);
            }
        }
        sort(sum.begin(), sum.end());
        int res = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            res = (res + sum[i]) % MOD;
        }
        return res;
    }
};
