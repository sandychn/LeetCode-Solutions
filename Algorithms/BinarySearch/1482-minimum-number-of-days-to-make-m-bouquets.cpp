class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = 1000000005;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(bloomDay, mid, m, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r > 1000000000 ? -1 : r;
    }

    bool check(vector<int>& a, int day, int m, int k) {
        int canMake = 0;
        int adjacentCnt = 0;
        int n = a.size();
        for (int i = 0; i < n && canMake < m; i++) {
            if (a[i] <= day) {
                ++adjacentCnt;
                if (adjacentCnt >= k) {
                    ++canMake;
                    adjacentCnt = 0;
                }
            } else {
                adjacentCnt = 0;
            }
        }
        return canMake >= m;
    }
};
