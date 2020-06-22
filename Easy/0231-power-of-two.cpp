class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if n == INT_MIN, `-n` seems to be overflow.
        // but this doesn't matter because we check n > 0 first.
        return n > 0 && n == (n & -n);
    }
};
