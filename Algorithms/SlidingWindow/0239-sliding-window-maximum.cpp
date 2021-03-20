#include <vector>
#include <deque>
#include <utility>

using std::vector;
using std::deque;
using std::pair;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();

        deque<pair<int, int>> q; // first-pos, second-value
        vector<int> res;
        res.reserve(n - k + 1);

        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front().first >= k) q.pop_front();
            while (!q.empty() && q.back().second <= nums[i]) q.pop_back();
            q.emplace_back(i, nums[i]);
            if (i + 1 >= k) res.push_back(q.front().second);
        }
        return res;
    }
};
