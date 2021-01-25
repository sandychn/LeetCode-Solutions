class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> cnt(100);
        int n = dominoes.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int val1 = dominoes[i][0] * 10 + dominoes[i][1];
            int val2 = dominoes[i][1] * 10 + dominoes[i][0];
            res += cnt[val1];
            ++cnt[val1];
            if (val1 != val2)
            {
                ++cnt[val2];
            }
        }
        return res;
    }
};
