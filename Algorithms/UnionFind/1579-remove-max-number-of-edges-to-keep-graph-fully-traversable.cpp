class UnionFind {
public:
    UnionFind(int elementCount)
        :
        parent(elementCount + 1),
        setSize(elementCount + 1, 1),
        setCount(elementCount) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (setSize[x] > setSize[y]) std::swap(x, y);
        parent[x] = y;
        setSize[y] += setSize[x];
        --setCount;
        return true;
    }

    int size() const {
        return setCount;
    }

private:
    std::vector<int> parent;
    std::vector<int> setSize;
    int setCount;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
        UnionFind uf(n);
        int ans = 0;

        for (const std::vector<int>& edge : edges) {
            int tp = edge[0], x = edge[1], y = edge[2];
            if (tp == 3 && !uf.join(x, y)) ++ans;
        }

        UnionFind ufAlice(uf);
        UnionFind ufBob(uf);

        for (const std::vector<int>& edge : edges) {
            int tp = edge[0], x = edge[1], y = edge[2];
            if (tp == 1) {
                if (!ufAlice.join(x, y)) ++ans;
            } else if (tp == 2) {
                if (!ufBob.join(x, y)) ++ans;
            }
        }

        return ufAlice.size() == 1 && ufBob.size() == 1 ? ans : -1;
    }
};
