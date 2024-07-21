class Solution {
public:

    void dfs(int node, vector<int> adj[], stack<int>& stk, bool vis[], bool pathVis[], bool& cycle){
        if(cycle){return;}
        if(vis[node] && pathVis[node]){
            cycle = true;
            return;
        } else if(vis[node]){
            return;
        } // it is never possible that a node is pathVis but not vis, as pathVis, vis = true simultaneously and once vis, it can't be visited, so pathVis = true, means once it has been vis as well, so vis != false, in any case;
        vis[node] = true;
        pathVis[node] = true;
        for(auto child : adj[node]){
            dfs(child, adj, stk, vis, pathVis, cycle);
        }
        pathVis[node] = false;
        stk.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        bool vis[2001] = {false};
        bool pathVis[2001]= {false};
        vector<int> ans;
        vector<int> adj[n];
        for(auto val : prerequisites){
            int u = val[0];
            int v = val[1];
            adj[v].push_back(u);
        }
        stack<int> stk;
        // if(prerequisites)
        bool cycle = false;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, stk, vis, pathVis, cycle);
            }
            if(cycle){
                return ans;
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};