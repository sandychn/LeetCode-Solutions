class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        return twoSum_twoPointers(numbers, target);
    }

    vector<int> twoSum_twoPointers(vector<int>& numbers, int target) {
        const int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int v = numbers[l] + numbers[r];
            if (v == target) return {l + 1, r + 1};
            if (v > target) {
                --r;
            } else {
                ++l;
            }
        }
        return {};
    }

    vector<int> twoSum_binarySearch(vector<int>& numbers, int target) {
        const int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int need = target - numbers[i];
            int pos = lower_bound(numbers.begin(), numbers.end(), need) - numbers.begin();
            if (pos == i) ++pos;
            if (pos < n && numbers[pos] == need) return {i + 1, pos + 1};
        }
        return {};
    }
};
