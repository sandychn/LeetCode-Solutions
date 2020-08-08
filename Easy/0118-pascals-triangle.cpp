class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        res.emplace_back(1, 1);
        for (int i = 2; i <= numRows; i++) {
            const vector<int>& last = res.back();
            vector<int> row;
            row.reserve(i);
            row.push_back(1);
            for (int j = 1; j < i - 1; j++) {
                row.push_back(last[j - 1] + last[j]);
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};
