class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<CHAR_MAX> bits;
        for (char ch : s) bits.flip(ch);
        return bits.count() <= 1;
    }
};
