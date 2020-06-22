class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        const int N = target.size();
        
        vector<string> res;

        int now = 1;
        for (int i = 0; i < N; i++) {
            while (now < target[i]) {
                res.push_back("Push");
                res.push_back("Pop");
                ++now;
            }
            res.push_back("Push");
            ++now;
        }
        
        return res;
    }
};
