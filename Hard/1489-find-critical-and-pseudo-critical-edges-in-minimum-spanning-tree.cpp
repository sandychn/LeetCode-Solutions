const int INF = 0x3F3F3F3F;
using PVI = pair<vector<int>, int>;

class Solution {
public:
    vector<int> fa;
    int size;

    void init(int n) {
        fa.resize(size = n);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    
    bool join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        fa[x] = y;
        --size;
        return true;
    }

    int kruskal(int n, const vector<PVI>& edges, int deleteEdgeId, int selectEdgeId) {
        const int M = edges.size();

        init(n);
        int sum = 0;

        auto update = [&sum, &edges, this](int edgeId) {
            int a = edges[edgeId].first[0];
            int b = edges[edgeId].first[1];
            int w = edges[edgeId].first[2];
            if (join(a, b)) sum += w;
        };

        if (selectEdgeId != -1) update(selectEdgeId);
        for (int i = 0; i < M && size > 1; i++) {
            if (i == deleteEdgeId) continue;
            update(i);
        }

        return size == 1 ? sum : INF;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        const int M = edges.size();

        vector<PVI> sortedEdges;
        for (int i = 0; i < M; i++) sortedEdges.emplace_back(edges[i], i);
        sort(sortedEdges.begin(), sortedEdges.end(), [](const PVI& e1, const PVI& e2) {
            int w1 = e1.first[2], w2 = e2.first[2];
            return w1 < w2;
        });

        vector<vector<int>> res(2);
        vector<int>& criticalEdges = res[0];
        vector<int>& pseudoCriticalEdges = res[1];
        
        int minCost = kruskal(n, sortedEdges, -1, -1);
        vector<char> isCritialEdge(M); // use vector<char> instead of vector<bool>

        for (int deleteEdgeId = 0; deleteEdgeId < M; deleteEdgeId++) {
            int cost = kruskal(n, sortedEdges, deleteEdgeId, -1);
            if (cost > minCost) {
                criticalEdges.push_back(sortedEdges[deleteEdgeId].second);
                isCritialEdge[deleteEdgeId] = 1;
            }
        }

        for (int selectEdgeId = 0; selectEdgeId < M; selectEdgeId++) {
            if (isCritialEdge[selectEdgeId]) continue;
            int cost = kruskal(n, sortedEdges, -1, selectEdgeId);
            if (cost == minCost) {
                pseudoCriticalEdges.push_back(sortedEdges[selectEdgeId].second);
            }
        }

        return res;
    }
};
