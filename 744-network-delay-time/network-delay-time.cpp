class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto val : times){
            int u = val[0];
            int v = val[1];
            int w = val[2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        // cout << "this is the adj list -> " << '\n';
        // int i = 0;
        // for(auto v : adj){
        //     cout << i++ << " -> " << " ";
        //     for(auto val : v){
        //         cout << "{"<< val.first << ", " << val.second << "}, ";
        //     } cout << '\n';
        // }
        // source is k
        // we need a pq that gives min time node first, {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> min_dist(n+1, INT_MAX);
        vector<bool> visited(n+1, false);
        pq.push({0, k});
        min_dist[k] = 0;
        while(!pq.empty()){
            auto parent = pq.top();
            int pval = parent.second;
            int pdis = parent.first;
            // cout << "this is pdis -> " << pdis << " for this parent -> " << pval << '\n'; 
            pq.pop();
            visited[pval]=true;
            for(auto child : adj[pval]){
                int cval = child.first;
                int cwt = child.second;
                if(!visited[cval] && min_dist[cval] > pdis + cwt){
                    pq.push({pdis + cwt, cval});
                    min_dist[cval] = pdis + cwt;
                }
            }
        }
        // cout << "this is min_dist vector -> " << '\n';
        // for(auto val : min_dist){
        //     cout << val << ' ';
        // } cout << '\n';
        int maxval = -1;
        int i = 0;
        for(auto val : min_dist){
            if(i > 0 && val == INT_MAX){return -1;}
            i++;
            if(val != INT_MAX && val > maxval){
                maxval = val;
            }
        }
        if(maxval==0){return -1;}
        return maxval;
        // return *max_element(++(min_dist.begin()), min_dist.end());
    }
};