class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        const int N = A.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ++mp[A[i] + B[j]];
            }
        }
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int sum = C[i] + D[j];
                auto it = mp.find(-sum);
                if (it != mp.end()) res += it->second;
            }
        }
        return res;
    }
};
