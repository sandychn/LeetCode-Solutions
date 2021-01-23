class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int prev = -1e9 - 5;
        int now = 0;
        int ans = 0;
        for (int num : nums)
        {
            if (prev < num)
            {
                ans = max(ans, ++now);
            }
            else
            {
                now = 1;
            }
            prev = num;
        }
        return ans;
    }
};
