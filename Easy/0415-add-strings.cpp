class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry = 0;
        for (int p = (int)num1.size() - 1, q = (int)num2.size() - 1; p >= 0 || q >= 0; --p, --q) {
            int now = carry;
            now += (p >= 0 ? num1[p] - '0' : 0) + (q >= 0 ? num2[q] - '0' : 0);
            carry = now / 10;
            res.push_back(now % 10 + '0');
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};
