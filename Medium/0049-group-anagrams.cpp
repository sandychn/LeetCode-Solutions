class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();
        
        unordered_map<string, int> mp;
        vector<vector<string>> res;

        for (int i = 0; i < N; i++) {
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            auto it = mp.find(tmp);
            if (it == mp.end()) {
                it = mp.emplace(tmp, mp.size()).first;
                res.push_back(vector<string>());
            }
            res[it->second].push_back(strs[i]);
        }

        return res;
    }
};
