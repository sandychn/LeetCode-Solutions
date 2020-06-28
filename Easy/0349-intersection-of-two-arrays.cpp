class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : nums2) {
            if (st.count(num)) {
                res.push_back(num);
                st.erase(num); // each element in `res` should be unqique
            }
        }
        return res;
    }
};
