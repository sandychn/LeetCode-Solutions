class Solution {
public:
    bool dfs(const vector<vector<int>>& graph, vector<int>& colors, int pos) {
        for (size_t i = 0; i < graph[pos].size(); i++) {
            int to = graph[pos][i];
            if (colors[to] != -1 && colors[pos] ^ 1 != colors[to]) {
                return false;
            }
            if (colors[to] == -1) {
                colors[to] = colors[pos] ^ 1;
                if (!dfs(graph, colors, to)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();

        vector<int> colors(N, -1);
        for (int i = 0; i < N; i++) {
            if (colors[i] == -1) {
                colors[i] = 0;
                if (!dfs(graph, colors, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};
