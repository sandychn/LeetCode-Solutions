class Solution {
public:
    int change(int x) {
        int ret = 0;
        while (x) {
            int digit = x % 10;
            x /= 10;
            ret += digit * digit;
        }
        return ret;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while (!st.count(n)) {
            if (n == 1) return true;
            st.insert(n);
            n = change(n);
        }
        return false;
    }
};
