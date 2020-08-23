class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n &= (n - 1);
        }
        return n;
    }

    int rangeBitwiseAnd_shift(int m, int n) {
        int shift = 0;
        // 公共前缀
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};
