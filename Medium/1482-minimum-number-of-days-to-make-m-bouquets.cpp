class Solution {
public:
    int check(vector<int>& bloomDay, int day, int m, const int k) {
        int successive = 0;
        int cnt = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (day < bloomDay[i]) {
                successive = 0;
            } else {
                ++successive;
                if (successive >= k) {
                    --m;
                    successive = 0;
                    if (m == 0) return true;
                }
            }
        }
        return false;
    }
    
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
        return r == 1000000005 ? -1 : r;
    }
};
