typedef double db;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& p, int s, int e) {
        vector<vector<pair<int,double>>> adj(n);
        int m = edges.size();
        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt= p[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // cout << "this is initial adj -> " << '\n';
        // int i = 0;
        // for(auto v : adj ){
        //     cout << i++ << " -> ";
        //     for(auto val : v){
        //         cout << "{" << val.first << ", " << val.second << "}, ";
        //     } cout << '\n';
        // }
        // priority_queue<pair<db, int>, vector<pair<db, int>>, greater<pair<db, int>>> pq; // node always integer
        priority_queue<pair<db, int>> pq;
        vector<bool> explored(n, false);
        vector<db> min_dist(n, 1.0*(-1));
        // cout << "this is initial min_dist -> " << '\n';
        // for(auto val : min_dist){
        //     cout << val << ' ';
        // } cout << '\n';
        pq.push({1.0, s});  // probability of reaching source_node == 1;
        explored[s] = 0;
        while(!pq.empty()){
            auto parent = pq.top();
            auto pval = parent.second;
            auto pdist= parent.first;
            // cout << "pval -> " << pval << " pdist -> " << pdist << '\n';
            pq.pop();
            explored[pval]=true;
            for(auto child : adj[pval]){
                auto cval = child.first;
                auto cdist= child.second;
                // cout << "this is cval -> " << cval << " this is cdist -> " << cdist << '\n';
                if(!explored[cval] && min_dist[cval] < pdist * cdist){
                    min_dist[cval]=pdist*cdist;
                    pq.push({min_dist[cval], cval});
                    // cout << "updating " << cval << " and pushed -> " << min_dist[cval] << '\n';
                }
            }
        }
        // cout << "this is the min_dist vector -> " << '\n';
        // for(auto val : min_dist){
        //     cout << val << ' ';
        // } cout << '\n';
        if(min_dist[e] == 1.0*(-1)){return 1.0*0;}
        return min_dist[e];
    }
};