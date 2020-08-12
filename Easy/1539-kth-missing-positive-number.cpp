class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> occurred(2001);
        for (int v : arr) occurred[v] = 1;
        int cnt = 0;
        for (int i = 1; i <= 2000; i++) {
            if (occurred[i] == 0) ++cnt;
            if (cnt == k) return i;
        }
        return -1;
    }
};
