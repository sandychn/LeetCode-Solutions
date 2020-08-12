class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> sums{0};
        for (int i = 0; i < n; i++) sums.push_back(sums.back() + nums[i]);
        
        unordered_map<int, int> choices;
        choices.emplace(0, 0);
        int removed = -1;
        int res = 0;
        
        for (int i = 1; i <= n; i++) {
            int goal = sums[i] - target; // sums[i] - sums[x] == target
            auto it = choices.find(goal);
            if (it != choices.end()) {
                ++res;
                int endPos = it->second;
                for (int j = removed + 1; j < i; j++) {
                    choices.erase(sums[j]);
                }
                removed = i - 1;
            }
            choices.emplace(sums[i], i);
        }
        
        return res;
    }
};
