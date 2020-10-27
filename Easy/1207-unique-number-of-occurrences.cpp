class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> cnt(2005);
        for (int value : arr) {
            ++cnt[value + 1000];
        }
        bitset<1005> exists;
        for (int value : cnt) {
            if (value) {
                if (exists.test(value)) return false;
                exists.set(value);
            }
        }
        return true;
    }
};
