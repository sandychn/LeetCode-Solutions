class Solution {
public:
    string getPermutation(int n, int k) {
        static const int factorialList[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        int res = 0;
        --k;
        for (int m = n - 1; m >= 0; m--) {
            int fac = factorialList[m];
            int r = k / fac;
            res = res * 10 + nums[r];
            nums.erase(nums.begin() + r);
            k %= fac;
        }
        return to_string(res);
    }
};
