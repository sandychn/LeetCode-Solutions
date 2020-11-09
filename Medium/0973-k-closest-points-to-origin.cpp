class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        };

        nth_element(points.begin(), points.begin() + K - 1, points.end(), compare);
        int limit = points[K - 1][0] * points[K - 1][0] + points[K - 1][1] * points[K - 1][1];

        vector<vector<int>> ans;
        ans.reserve(K);
        copy_if(points.begin(), points.end(), back_inserter(ans), [limit](const vector<int>& point) {
            return point[0] * point[0] + point[1] * point[1] <= limit;
        });
        
        return ans;

        // partial_sort(points.begin(), points.begin() + K, points.end(), compare);
        // return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
