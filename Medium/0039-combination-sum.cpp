class Solution {
public:
    vector<int> candidates;
    vector<int> selectCount;
    vector<vector<int>> res;
    int target;
    int n;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->selectCount = vector<int>(candidates.size());
        this->res.clear();
        this->target = target;
        this->n = candidates.size();

        sort(this->candidates.rbegin(), this->candidates.rend());
        solve(0, 0);
        return res;
    }

    // selectCandidatesCount is for vector reserve to get better performance
    void solve(int pos, int nowSum, int selectCandidatesCount = 0) {
        if (nowSum == target) {
            addToResult(selectCandidatesCount);
            return;
        }

        if (pos >= n) {
            return;
        }
        
        for (int i = 0, val = candidates[pos]; nowSum + val * i <= target; i++) {
            selectCount[pos] = i;
            solve(pos + 1, nowSum + val * i, selectCandidatesCount + i);
        }
        selectCount[pos] = 0;
    }

    inline void addToResult(int selectCandidatesCount) {
        vector<int> sol;
        sol.reserve(selectCandidatesCount);
        for (int i = 0; i < n; i++) {
            int cnt = selectCount[i];
            int val = candidates[i];
            while (cnt--) sol.push_back(val);
        }
        res.push_back(sol);
    }
};
