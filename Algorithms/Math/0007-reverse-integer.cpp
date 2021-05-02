class Solution {
public:
    static const int OVERFLOW = 0;

    static const int INT_MIN_DIV_10 = INT_MIN / 10;
    static const int INT_MAX_DIV_10 = INT_MAX / 10;
    static const int INT_MIN_MOD_10 = INT_MIN % 10;
    static const int INT_MAX_MOD_10 = INT_MAX % 10;

    int reverse(int x) {
        int ans = 0;
        while (x) {
            int digit = x % 10;
            if (ans < 0) {
                if (ans < INT_MIN_DIV_10 || (ans == INT_MIN_DIV_10 && digit < INT_MIN_MOD_10)) return OVERFLOW;
            } else {
                if (ans > INT_MAX_DIV_10 || (ans == INT_MAX_DIV_10 && digit > INT_MAX_MOD_10)) return OVERFLOW;
            }
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};
