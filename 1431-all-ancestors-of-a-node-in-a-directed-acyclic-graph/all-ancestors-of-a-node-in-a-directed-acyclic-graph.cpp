class Solution {
public:

    void traverse(int node, vector<vector<int>>& parent, vector<vector<int>>& adj, int root, vector<bool>& vis){
        vis[node] = true;
        for(auto val : adj[node]){
            if(vis[val]){continue;}
            parent[val].push_back(root);
            traverse(val, parent, adj, root, vis);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> parent(n);
        vector<vector<int>> adj(n);
        for(auto val : edges){
            int x = val[0];
            int y = val[1];
            adj[x].push_back(y);
        }
        for(int node = 0; node < n; node++){
            vector<int> ancestor;
            vector<bool> vis(n, false);
            traverse(node, parent, adj, node, vis);
        }
        return parent;
    }
};