class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();

        vector<char> res(n);
        vector<int> cnt(26);
        for (char ch : S) ++cnt[ch - 'a'];
        int mostCommonLetterId = max_element(begin(cnt), end(cnt)) - begin(cnt);

        if (cnt[mostCommonLetterId] > (n + 1) / 2) {
            return "";
        }

        if (cnt[mostCommonLetterId] == (n + 1) / 2) {
            for (int i = 0; i < n; i += 2) {
                res[i] = mostCommonLetterId + 'a';
            }
            cnt[mostCommonLetterId] = 0;
            for (int i = 1, p = 0; i < n; i += 2) {
                while (cnt[p] == 0) ++p;
                --cnt[p];
                res[i] = p + 'a';
            }
        } else {
            for (int i = 0, p = 0; i < n; i += 2) {
                while (cnt[p] == 0) ++p;
                --cnt[p];
                res[i] = p + 'a';
            }
            for (int i = 1, p = 0; i < n; i += 2) {
                while (cnt[p] == 0) ++p;
                --cnt[p];
                res[i] = p + 'a';
            }
        }

        return string(begin(res), end(res));
    }
};
