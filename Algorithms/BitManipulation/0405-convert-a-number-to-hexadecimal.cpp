class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string ret;
        for (int i = 7; i >= 0; i--)
        {
            int v = (num >> (i * 4)) & 0xF;
            if (ret.empty() && v == 0) continue;
            ret += "0123456789abcdef"[v];
        }
        return ret;
    }
};
