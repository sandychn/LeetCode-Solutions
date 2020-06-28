class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        int i = 0;
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) {
                ++cnt;
                if (cnt > 2) continue;
            } else {
                cnt = 1;
            }
            nums[i++] = nums[j];
        }
        return i;
    }
};
