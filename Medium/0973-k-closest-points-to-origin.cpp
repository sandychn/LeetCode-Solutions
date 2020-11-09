class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compare = [](const vector<int>& v1, const vector<int>& v2) {
            int dist1 = v1[0] * v1[0] + v1[1] * v1[1];
            int dist2 = v2[0] * v2[0] + v2[1] * v2[1];
            return dist1 < dist2;
        };

        partial_sort(points.begin(), points.begin() + K, points.end(), compare);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
