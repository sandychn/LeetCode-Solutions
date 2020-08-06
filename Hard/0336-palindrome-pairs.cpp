class Solution {
public:
    using hash_t = uint64_t;
    static const hash_t SEED = 131;

    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int N = words.size();

        // hash value, reversed hash value
        pair<hash_t, hash_t>* hv = new pair<hash_t, hash_t>[N];
        size_t maxLen = 0;

        for (int i = 0; i < N; i++) {
            hv[i] = getHash(words[i]);
            maxLen = max(maxLen, words[i].size());
        }

        hash_t* powers = new hash_t[maxLen + 1];
        powers[0] = 1;
        for (int i = 1; i <= maxLen; i++) powers[i] = powers[i - 1] * SEED;

        vector<vector<int>> res;
        for (int i = 0; i < N; i++) {
            size_t aSize = words[i].size();
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                size_t bSize = words[j].size();
                hash_t x = hv[i].first * powers[bSize] + hv[j].first;
                hash_t y = hv[j].second * powers[aSize] + hv[i].second;
                if (x == y) {
                    res.push_back({i, j});
                }
            }
        }

        delete[] powers;
        delete[] hv;
        return res;
    }

    pair<hash_t, hash_t> getHash(const string& word) {
        hash_t h = 0, rh = 0;
        size_t n = word.size();
        for (size_t i = 0; i < n; i++) {
            h = h * SEED + word[i];
            rh = rh * SEED + word[n - 1 - i];
        }
        return {h, rh};
    }
};
