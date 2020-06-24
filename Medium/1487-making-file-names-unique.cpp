class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> cnt;
        unordered_set<string> occurred;
        vector<string> res;
        
        for (const string& name : names) {
            if (occurred.count(name)) {
                int& id = ++cnt[name];
                while (occurred.count(name + '(' + to_string(id) + ')') > 0) ++id;
                string tmp = name + '(' + to_string(id) + ')';
                res.push_back(tmp);
                occurred.insert(tmp);
            } else {
                res.push_back(name);
                occurred.insert(name);
            }
        }
        
        return res;
    }
};
