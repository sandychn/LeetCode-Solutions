class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : nums2) {
            auto it = st.find(num);
            if (it != st.end()) {
                st.erase(it);
                res.push_back(num);
            }
        }
        return res;
    }
};
