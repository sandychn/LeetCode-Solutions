class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        const size_t n = name.size();
        const size_t m = typed.size();
        size_t i = 0;
        size_t j = 0;
        char current = 0;

        while (j < m) {
            if (i < n && name[i] == typed[j]) {
                current = name[i];
                ++i;
                ++j;
            } else if (typed[j] == current) {
                ++j;
            } else {
                return false;
            }
        }
        
        return i == n;
    }
};
