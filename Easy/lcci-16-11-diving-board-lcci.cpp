class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) return vector<int>();
        if (shorter == longer) return vector<int>{shorter * k};

        vector<int> res;
        res.reserve(k + 1);
        for (int i = k; i >= 0; i--) {
            res.push_back(shorter * i + longer * (k - i));
        }
        return res;
    }
};
