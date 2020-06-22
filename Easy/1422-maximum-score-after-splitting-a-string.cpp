class Solution {
public:
    int maxScore(string s) {
        const int N = s.size(); // N >= 2

        int zeroInLeft = (s[0] == '0');
        int oneInRight = count(s.begin() + 1, s.end(), '1');
        int ans = zeroInLeft + oneInRight;

        // split string into [0, i] and [i + 1, N)
        for (int i = 1; i < N - 1; i++) {
            if (s[i] == '1') --oneInRight;
            else ++zeroInLeft;
            ans = max(ans, zeroInLeft + oneInRight);
        }
        return ans;
    }
};
