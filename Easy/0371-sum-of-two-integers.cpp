class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned carry = a & b;
            carry <<= 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
