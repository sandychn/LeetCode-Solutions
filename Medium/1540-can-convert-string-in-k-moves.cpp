class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size(), m = t.size();
        if (n != m) return false;
        
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            char a = s[i], b = t[i];
            if (a < b) {
                cnt[b - a]++;
            } else if (a > b) {
                cnt[26 - (a - b)]++;
            }
        }
        
        for (int i = 1; i < 26; i++) {
            if (cnt[i] > get(k, i)) return false;
        }
        
        return true;
    }
    
    int get(int k, int x) { // [1, k] 有多少个 y 满足 k % y == x
        return k / 26 + (k % 26 >= x);
    }
};
