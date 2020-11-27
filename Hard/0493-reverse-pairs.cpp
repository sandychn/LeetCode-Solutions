class Solution {
public:
    using LL = long long;

    int reversePairs(vector<int>& nums) {
        vector<LL> values;
        values.reserve(nums.size() * 2);
        for (int num : nums) {
            values.push_back(num);
            values.push_back(num * 2LL);
        }
        sort(begin(values), end(values));
        values.erase(unique(begin(values), end(values)), end(values));

        unordered_map<LL, int> id;
        id.reserve(values.size());
        for (int i = 0, n = values.size(); i < n; i++) id[values[i]] = i + 1;

        init(values.size() + 1);
        int res = 0;
        for (int j = 0, n = nums.size(); j < n; j++) {
            int value = nums[j];
            int biggerCount = j - sum(id[2LL * nums[j]]);
            res += biggerCount;
            add(id[value], 1);
        }

        return res;
    }

private:
    vector<int> fenwick;

    void init(int n) {
        fenwick = vector<int>(n + 1);
    }

    void add(int pos, int val) {
        for (int n = fenwick.size(); pos < n; pos += lowbit(pos)) {
            fenwick[pos] += val;
        }
    }

    int sum(int pos) {
        int res = 0;
        while (pos > 0) {
            res += fenwick[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    static int lowbit(int x) {
        return x & -x;
    }
};
