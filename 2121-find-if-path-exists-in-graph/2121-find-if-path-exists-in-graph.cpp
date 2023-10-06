class Solution {
public:

    bool vis[200000] = {false};
    void dfs(int node, int d, vector<int> adj[], bool& isFound)
    {
        vis[node] = true;
        if(node==d){isFound=true;}
        if(isFound==true){return;}
        for(auto child : adj[node])
        {
            if(vis[child]){continue;}
            dfs(child, d, adj, isFound);
            // if(isFound==true){return;}
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<int> adj[n];
        int m = edges.size();
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // bool vis[n] = {false};
        // for(int i = 0; i < n; i++)
        // {
        //     if(!vis[i])
        //     {
        //         // CALL THE DFS ALGO;
        //     }
        // }
        // we should call dfs starting only from source;
        bool isFound = false;
        dfs(source, destination, adj, isFound);
        return isFound;
    }
};