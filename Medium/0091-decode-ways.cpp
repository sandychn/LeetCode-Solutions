class Solution {
public:
    int numDecodings(string s) {
        const int N = s.size();
        if (N == 0 || s[0] == '0') return 0;

        int ppre = 1, pre = 1;
        for (int i = 1; i < N; i++) {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            if (a == 0 && b == 0) return 0;
            int now = 0;
            if (1 <= a && a <= 2 && a * 10 + b <= 26) // 可以与前面一个数字拼起来
                now += ppre;
            if (b != 0)  // 可以自己单独作为一个数字
                now += pre;
            ppre = pre;
            pre = now;
        }
        return pre;
    }
};
