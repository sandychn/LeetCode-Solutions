class Solution {
public:
    struct Node {
        int cnt, l, r;
        Node(): cnt(0), l(-1), r(-1) {}
    };

    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, Node> h;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto& t = h[nums[i]];
            if (t.cnt == 0) t.l = i;
            t.r = i;
            maxCount = max(maxCount, ++t.cnt);
        }
        int ans = nums.size();
        for (const auto& [v, node] : h)
            if (node.cnt == maxCount)
                ans = min(ans, node.r - node.l + 1);
        return ans;
    }
};
