class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();

        unordered_map<int, int> hash;
        for (int i = 0; i < n; ++i) {
            hash.emplace(nums[i], i);
            auto it = hash.find(target - nums[i]);
            if (it != hash.end() && it->second != i) {
                return vector<int>{static_cast<int>(i), static_cast<int>(it->second)};
            }
        }
        return vector<int>();
    }
};
