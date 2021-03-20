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
    string minInteger(string num, int k) {
        const int N = num.size();

        if (2 * k >= N * (N - 1)) {
            sort(num.begin(), num.end());
            return num;
        }

        queue<int> pos[10];
        FenwickTree<int> tree(N);

        for (int i = 0; i < N; i++) pos[num[i] - '0'].push(i);

        string res;
        for (int i = 0; i < N; i++) {
            for (int digit = 0; digit < 10; digit++) {
                if (pos[digit].empty()) continue;
                int digitPos = pos[digit].front();
                int cost = digitPos - tree.sum(digitPos + 1);
                if (cost <= k) {
                    res += digit + '0';
                    k -= cost;
                    pos[digit].pop();
                    tree.add(digitPos + 1, 1);
                    break;
                }
            }
        }
        return res;
    }
};
