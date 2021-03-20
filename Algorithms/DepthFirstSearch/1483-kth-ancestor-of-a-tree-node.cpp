class TreeAncestor {
public:
    vector<vector<int>> edge;
    vector<vector<int>> path;
    vector<pair<int, int>> toLeaf; // leaf-id, step-to-leaf
    
    TreeAncestor(int n, vector<int>& parent) {
        edge.resize(n);
        path.resize(n);
        toLeaf.resize(n);
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) continue;
            edge[parent[i]].push_back(i);
        }
        vector<int> tmp;
        int theLeaf, theLeafDepth;
        dfs(0, tmp, theLeaf, theLeafDepth);
    }
    
    void dfs(int pos, vector<int>& tmp, int& theLeaf, int &theLeafDepth) {
        tmp.push_back(pos);
        int soncnt = 0;
        for (int to : edge[pos]) {
            dfs(to, tmp, theLeaf, theLeafDepth);
            ++soncnt;
        }
        if (soncnt == 0) {
            path[pos] = tmp;
            theLeafDepth = tmp.size();
            theLeaf = pos;
            toLeaf[pos] = {pos, 0};
        } else {
            toLeaf[pos] = {theLeaf, theLeafDepth - tmp.size()};
        }
        tmp.pop_back();
    }
    
    int getKthAncestor(int node, int k) {
        int leaf = toLeaf[node].first;
        int dis = toLeaf[node].second;
        int up = dis + k;
        
        const vector<int>& thePath = path[leaf];
        if (thePath.size() <= up) {
            return -1;
        }
        return thePath[thePath.size() - up - 1];
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
