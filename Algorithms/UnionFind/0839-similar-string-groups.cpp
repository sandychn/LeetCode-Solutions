class UnionFind {
public:
    UnionFind(int size): parent(size), setCount(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return;
        parent[x] = y;
        --setCount;
    }

    int size() const {
        return setCount;
    }

private:
    vector<int> parent;
    int setCount;
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        const int n = strs.size();
        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    uf.join(i, j);
                }
            }
        }

        return uf.size();
    }

    bool isSimilar(const string& a, const string& b) {
        int cnt = 0;
        const int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (++cnt > 2) return false;
            }
        }
        return true;
    }
};
