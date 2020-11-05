class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int x, int y) {
            auto p = __builtin_popcount(x); // bitset<32>(x).count()
            auto q = __builtin_popcount(y); // bitset<32>(y).count()
            return p == q ? x < y : p < q;
        });
        return arr;
    }
};
