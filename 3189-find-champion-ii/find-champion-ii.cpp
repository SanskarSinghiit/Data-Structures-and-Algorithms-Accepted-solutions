class Solution {
public:

    // void dfs(int i, vector<vector<int>>& adj, stack<int>& stk, vector<bool>& vis){
    //     vis[i]=true;
    //     for(auto val : adj[i]){
    //         if(!vis[val]){
    //             dfs(val,adj,stk,vis);
    //         }
    //     }
    //     stk.push(i);
    // }


    // void get_topo_sort(vector<vector<int>>& adj, vector<int>& topo){
    //     int n = adj.size();
    //     vector<bool> vis(n, false);
    //     stack<int> stk;
    //     for(int i = 0; i < n; i++){
    //         if(!vis[i]){
    //             dfs(i, adj, stk, vis);
    //         }
    //     }
    //     while(!stk.empty()){
    //         topo.push_back(stk.top());
    //         stk.pop();
    //     }
    // }

    // bool find_u_v(int x, int y, vector<vector<int>>& adj){
    //     for(auto val : adj[x]){
    //         if(val==y){return true;}
    //     } return false;
    // }

    int findChampion(int n, vector<vector<int>>& edges) {
        // int m = edges.size();
        // vector<vector<int>> adj(n);
        // for(auto val : edges){
        //     int u = val[0]; int v = val[1];
        //     adj[u].push_back(v);
        // }
        vector<bool> vec(n, true);
        for(auto val : edges){
            int u = val[0];
            int v = val[1];
            vec[v]=false;
        }
        int count = 0;
        int ans=-2;
        // cout << "this is vec -> ";
        // for(auto val : vec){
        //     cout << val << ' ';
        // } cout << '\n';
        for(int i = 0; i < n; i++){
            if(vec[i]){count++; ans = i;}
        }
        if(count == 1){return ans;}
        return -1;
        // vector<int> topo;
        // get_topo_sort(adj, topo);
        // if(find_u_v(topo[0],topo[1],adj)){return topo[0];}
        // return -1;
    }
};