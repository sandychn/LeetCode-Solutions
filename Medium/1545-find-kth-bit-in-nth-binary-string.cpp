class Solution {
public:
    string invertReverse(const string& s) {
        string res;
        res.reserve(s.size());
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; i--)
            res.push_back(s[i] ^ 1);
        return res;
    }
    
    char findKthBit(int n, int k) {
        string s[2];
        s[1] = "0";
        for (int i = 2; i <= n; i++) {
            int y = i & 1, x = y ^ 1;
            s[y] = s[x];
            s[y] += "1";
            s[y] += invertReverse(s[x]);
            if (s[y].size() >= k) return s[y][k - 1];
        }
        return s[n & 1][k - 1];
    }
};
