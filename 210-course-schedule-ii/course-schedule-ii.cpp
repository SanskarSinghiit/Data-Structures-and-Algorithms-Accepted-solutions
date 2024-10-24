#define v vector
class Solution {
public:

    bool dfs(int node, v<bool>& vis, v<v<int>>& adj, v<bool>& path_vis, stack<int>& stk){
        vis[node]=true;
        path_vis[node]=true;
        for(auto child : adj[node]){
            if(path_vis[child]){return true;}
            if(!vis[child]){
                bool is_cycle = dfs(child, vis, adj, path_vis, stk);
                if(is_cycle){return true;}
            }
        }
        stk.push(node);
        path_vis[node]=false;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // also we have to consider case if the graph got cycle
        // also we have to consider the case if the graph is disconnected;
        // int n = pre
        v<v<int>> adj(n);
        v<bool> vis(n, false);
        v<bool> path_vis(n, false);
        for(auto val : prerequisites){
            int u = val[1];
            int v = val[0];
            adj[u].push_back(v);
        }
        stack<int> stk;
        for(int node = 0; node < n; node++){
            if(!vis[node]){
                bool is_cycle = dfs(node, vis, adj, path_vis, stk);
                if(is_cycle){return {};}
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};