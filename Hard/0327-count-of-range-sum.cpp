class FenwickTree {
public:
    FenwickTree(int n): tree_(n + 1), n_(n) {}
    
    void add(int pos, int val) {
        for (; pos <= n_; pos += lowbit(pos)) tree_[pos] += val;
    }

    int sum(int pos) {
        int res = 0;
        for (; pos > 0; pos -= lowbit(pos)) res += tree_[pos];
        return res;
    }

private:
    vector<int> tree_;
    int n_;

    static int lowbit(int x) { return x & -x; }
};

class Solution {
public:
    using LL = long long;

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int n = nums.size();
        if (n == 0) return 0;

        LL prefixSum = 0;
        vector<LL> values;

        values.reserve(3 * n + 1);
        values.push_back(0);

        // lower <= prefixSum - value <= upper
        // -upper <= value - prefixSum <= -lower
        // prefixSum - upper <= value <= prefixSum - lower

        for (int num : nums) {
            prefixSum += num;
            values.push_back(prefixSum);
            values.push_back(prefixSum - upper - 1);
            values.push_back(prefixSum - lower);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        unordered_map<LL, int> valueToID;
        valueToID.reserve(values.size());

        for (int i = 0, size = values.size(); i < size; i++) {
            valueToID[values[i]] = i + 1;
        }

        FenwickTree fenwickTree(values.size());

        prefixSum = 0;
        fenwickTree.add(valueToID[prefixSum], 1);

        int res = 0;
        for (int num : nums) {
            prefixSum += num;
            int low = fenwickTree.sum(valueToID[prefixSum - upper - 1]);
            int up = fenwickTree.sum(valueToID[prefixSum - lower]);
            res += up - low;
            fenwickTree.add(valueToID[prefixSum], 1);
        }

        return res;
    }
};
