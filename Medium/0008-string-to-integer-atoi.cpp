class Solution {
public:
    int myAtoi(string str) {      
        if (str.empty()) {
            return 0;
        }

        int res = 0;
        bool neg = false;
        int i = 0;

        while (str[i] == ' ') i++;

        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            neg = true;
            i++;
        }

        while (i < str.size() && isdigit(str[i])) {
            int now = str[i] - '0';
            if (neg) {
                if (res < INT_MIN / 10 || (res == INT_MIN / 10 && now > INT_MAX % 10 + 1)) {
                    return INT_MIN;
                }
                res = res * 10 - now;
            } else {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && now > INT_MAX % 10)) {
                    return INT_MAX;
                }
                res = res * 10 + now;
            }
            i++;
        }
        return res;
    }
};
