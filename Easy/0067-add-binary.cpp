class Solution {
public:
    string addBinary(string a, string b) {
        const int N = max(a.size(), b.size());
        
        string res;
        int carry = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < N; i++) {
            int x = i < a.size() ? a[i] - '0' : 0;
            int y = i < b.size() ? b[i] - '0' : 0;
            res.push_back(((x + y + carry) & 1) + '0');
            if (x + y + carry > 1) carry = 1;
            else carry = 0;
        }
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
