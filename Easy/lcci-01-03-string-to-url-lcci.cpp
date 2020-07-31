class Solution {
public:
    string replaceSpaces(string S, int length) {
        int p = length - 1;
        int q = length + count(S.begin(), S.begin() + length, ' ') * 2;
        S[q] = '\0';
        for (; p >= 0; --p) {
            if (S[p] == ' ') {
                S[--q] = '0';
                S[--q] = '2';
                S[--q] = '%';
            } else {
                S[--q] = S[p];
            }
        }
        return S;
    }
};
