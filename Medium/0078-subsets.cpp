class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, nums, tmp, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, const vector<int>& nums, vector<int>& now, int pos) {
        if (pos == nums.size()) {
            res.push_back(now);
            return;
        }
        now.push_back(nums[pos]);
        dfs(res, nums, now, pos + 1);
        now.pop_back();
        dfs(res, nums, now, pos + 1);
    }
};

class MySolution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> tmp;
            for (int j = 0, p = i; p; j++, p >>= 1) {
                if (p & 1) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
