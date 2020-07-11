template<typename T>
class FenwickTree {
public:
    FenwickTree(int _n): tree(new T[_n + 1]()), n(_n) {}
    ~FenwickTree() { delete[] tree; }

    T sum(int x) {
        T res = 0;
        while (x > 0) {
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }

    void add(int pos, T delta) {
        while (pos <= n) {
            tree[pos] += delta;
            pos += lowbit(pos);
        }
    }

private:
    T* tree;
    int n;

    static int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        vector<int> v(nums);

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        
        FenwickTree<int> bit(v.size());
        vector<int> res(N);
        for (int i = N - 1; i >= 0; i--) {
            int id = lower_bound(v.begin(), v.end(), nums[i]) - v.begin() + 1;
            res[i] = bit.sum(id - 1);
            bit.add(id, 1);
        }

        return res;
    }
};
