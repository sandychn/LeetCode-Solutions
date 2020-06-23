class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        partial_sum(nums.begin(), nums.end(), back_inserter(res));
        return res;
    }
};
