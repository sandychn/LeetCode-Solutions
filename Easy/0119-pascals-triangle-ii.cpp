class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p[2] = {{1}, {1, 1}};
        for (int i = 2; i <= rowIndex; i++) {
            int id = i & 1;
            p[id].clear();
            p[id].push_back(1);
            for (int j = 1; j < i; j++) {
                p[id].push_back(p[id ^ 1][j] + p[id ^ 1][j - 1]);
            }
            p[id].push_back(1);
        }
        return p[rowIndex & 1];
    }
};
