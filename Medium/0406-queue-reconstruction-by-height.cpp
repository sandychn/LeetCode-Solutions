class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        using VI = vector<int>;
        auto compare = [](const VI& a, const VI& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        };
        sort(begin(people), end(people), compare);

        deque<VI> res;
        for (const VI& person: people) {
            res.insert(begin(res) + person[1], person);
        }

        return vector<VI>(begin(res), end(res));
    }
};
