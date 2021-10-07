class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int length = s.size();
        if (length < 10) return {};

        std::unordered_map<int, int> counter;
        std::vector<std::string> ans;

        int v = 0;
        const int mask = (1 << 20) - 1;
        for (int i = 0; i < 9; i++) v = (v << 2) | hashValue(s[i]);
        for (int i = 9; i < length; i++) {
            v = ((v << 2) | hashValue(s[i])) & mask;
            if (++counter[v] == 2) {
                ans.push_back(s.substr(i - 9, 10));
            }
        }

        return ans;
    }

    static int hashValue(char ch) {
        switch (ch) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
        return -1;
    }
};
