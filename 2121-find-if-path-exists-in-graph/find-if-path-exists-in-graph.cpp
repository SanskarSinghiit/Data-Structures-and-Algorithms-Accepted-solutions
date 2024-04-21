class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> q;
        vector<int> adj[n];
        bool vis[200001] = {false};
        int m = edges.size();
        for(int i = 0; i < m; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // cout << "printing adjacency list => " << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << "for " << i << " => ";
        //     for(auto val : adj[i]){
        //         cout << val << ' ';
        //     } cout << '\n';
        // }
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==destination){
                return true;
            }
            for(auto child : adj[node]){
                if(vis[child]){
                    continue;
                }
                q.push(child);
                vis[child] = true;
            }
        }
        return false;
    }
};