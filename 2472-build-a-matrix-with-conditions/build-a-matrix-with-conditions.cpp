class Solution {
public:

    void dfs(int node, vector<int> adj[], stack<int>& stk, bool vis[], bool pathVis[], bool& cycle){
        if(cycle){return;}
        if(vis[node] && pathVis[node]){
            cycle = true;
            return;
        } else if(vis[node]){
            return;
        } 
        vis[node] = true;
        pathVis[node] = true;
        for(auto child : adj[node]){
            dfs(child, adj, stk, vis, pathVis, cycle);
        }
        pathVis[node] = false;
        stk.push(node);
    }

    void getTopoSort(vector<int> adj[], int k, vector<int>& ts, bool& foundCycle){
        stack<int> stk;
        bool vis[401] = {false};
        bool pathVis[401] = {false};
        // bool foundCycle = false;
        for(int i = 1; i <= k; i++){
            if(!vis[i]){
                dfs(i, adj, stk, vis, pathVis, foundCycle);
            }
            if(foundCycle){
                return;
            }
        }
        while(!stk.empty()){
            ts.push_back(stk.top());
            stk.pop();
        }
    }

    void print(vector<int>& ts){
        for(auto val : ts){
            cout << val << ' ';
        } cout << '\n';
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<vector<int>> mat(k, vector<int>(k, 0));
        vector<vector<int>> tmp;
        // cout << "printing initial matrix => " << '\n';
        // for(auto v : mat){
        //     for(auto x : v){
        //         cout << x << ' ';
        //     } cout << '\n';
        // }
        // int n = rc.size(); int m = cc.size();
        vector<int> adjr[k+1], adjc[k+1];
        for(auto val : rc){
            int u = val[0];
            int v = val[1];
            // u should appear above v, means u -> v, directed edge;
            adjr[u].push_back(v);
        }
        for(auto val : cc){
            int u = val[0];
            int v = val[1];
            // u should appear left of v; means u->v, directed edge;
            adjc[u].push_back(v);
        }
        vector<int> topor, topoc;
        bool foundCycle = false;
        getTopoSort(adjr, k, topor, foundCycle);
        if(foundCycle){return tmp;}
        getTopoSort(adjc, k, topoc, foundCycle);
        if(foundCycle){return tmp;}
        // cout << "printing topor => " << " ";
        // print(topor);
        // cout << "printing topoc => " << " ";
        // print(topoc);
        // CODE WORKS FINE TILL NOW ------------------------;
        // fill 1st col with topor;
        // somehow make a ds, that inputs node, and tells at which row it is, obvoisly col=0, and row = r;
        // maybe a hashmap --> O(1), gives answer;
        int hashmap[401];
        for(int i = 0; i < k; i++){ // k nodes 1, 2, 3, .....k, since topor is 0-based indexing thus we use i = 0;
            int node = topor[i];
            mat[i][0] = node;
            hashmap[node] = i; // 0th row for the first element of the toposort;
        }
        // int icol = 0;
        // cout << "insie icol loop => " << '\n';
        for(int icol = 0; icol < k; icol++){
            // cout << "icol value => " << icol << " m value => " << m << '\n';
            int node = topoc[icol];
            // cout << "this is the node => " << node << "  ";
            int getRow = hashmap[node];
            // cout << "row, col it should go => " << getRow << ", " << icol << "  ";
            // cout << "curr value of icol => " << icol << '\n';
            // initially node at getRow, make it move to jth column, 
            mat[getRow][0] = 0;
            mat[getRow][icol] = node;
        }
        return mat;
    }
};