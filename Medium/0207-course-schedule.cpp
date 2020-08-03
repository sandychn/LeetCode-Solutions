class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        vector<vector<int>> edges(numCourses);

        for (const vector<int>& edge : prerequisites) {
            int a = edge[0], b = edge[1];
            edges[b].push_back(a);
            ++inDegree[a];
        }

        return toposort(numCourses, inDegree, edges);
    }

    bool toposort(int n, vector<int>& inDegree, const vector<vector<int>>& edges) {
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ++cnt;
            for (size_t i = 0; i < edges[now].size(); i++) {
                int to = edges[now][i];
                if (--inDegree[to] == 0) {
                    q.push(to);
                }
            }
        }
        return cnt == n;
    }

};
