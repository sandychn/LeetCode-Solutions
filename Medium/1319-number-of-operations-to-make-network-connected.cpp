class Solution {
public:
    vector<int> visited;
    vector<vector<int>> edges;

    void dfs(int now)
    {
        visited[now] = 1;
        for (int i = 0; i < edges[now].size(); i++)
        {
            int to = edges[now][i];
            if (!visited[to]) dfs(to);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1;

        visited = vector<int>(n);
        edges = vector<vector<int>>(n);

        for (const auto& edge : connections)
        {
            int x = edge[0], y = edge[1];
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        int parts = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                ++parts;
            }
        }

        return parts - 1;
    }
};
