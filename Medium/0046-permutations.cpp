class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, nums, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& now, const vector<int>& nums, int visit) {
        if (now.size() >= nums.size()) {
            ans.emplace_back(now);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!((visit >> i) & 1)) {
                now.push_back(nums[i]);
                dfs(ans, now, nums, visit | (1 << i));
                now.pop_back();
            }
        }
    }
};

class OfficalSolution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            backtrack(ans, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};
