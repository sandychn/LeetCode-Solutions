class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        using VI = vector<int>;
        auto compare = [](const VI& a, const VI& b) {
            return a[1] < b[1];
        };

        sort(begin(points), end(points), compare);
        
        int ans = 1;
        int right = points[0][1];
        for (int i = 0; i < n; i++) {
            int l = points[i][0];
            int r = points[i][1];
            if (l > right) {
                ++ans;
                right = r;
            } else {
                right = min(right, r);
            }
        }

        return ans;
    }
};
