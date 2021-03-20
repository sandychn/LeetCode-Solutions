class Solution {
public:
    int firstPos[1 << 10];

    int longestAwesome(string s) {
        memset(firstPos, 0x3F, sizeof(firstPos));
        firstPos[0] = -1;
        int n = s.size();
        int bset = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            bset ^= 1 << (s[i] - '0');
            res = max(res, i - firstPos[bset]);

            for (int j = 0; j < 10; j++) {
                res = max(res, i - firstPos[bset ^ (1 << j)]);
            }

            firstPos[bset] = min(firstPos[bset], i);
        }
        return res;
    }
};
