class Solution {
public:

    vector <int> dijkstra(int src, vector<vector<int>> adj[], int n)
    {
        // vector<int>
        // since we need unexplored node with smallest time, we will use pq, ;
        // if clash between two or more, choose any of them;
        // why pq, as it may change the order of bfs,
        // are we doing bfs? -> no we are not doing bfs, where we use a queue, so that,
        // we do level order traversal, instead we using an algorithm, that traverses, 
        // shortest time first;
        // bool explored[n] = {false};
        vector<bool> explored(n, false);
        vector<int> mind(n, INT_MAX);
        // by default pq is maxheap, that means stores in descending order, 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 /*time, node*/
        // this makes ascending,
        // so pq.top() // just like stacks //will be min time
        // explored[src] = true;
        mind[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            auto node = pq.top();  // chooosing min time node and make it explored
            pq.pop();
            // if(explored[node.second]){continue;}
            explored[node.second] = true;
            for(auto child : adj[node.second]){
                if(explored[child[0]]){ // as we will insert from only unexplored towns;
                    continue;
                } // else
                if(mind[child[0]] < node.first + child[1]){
                    // don't modify mind, 
                } else{
                    mind[child[0]] = node.first + child[1];
                    pq.push({mind[child[0]], child[0]});
                }
            }
            // also remember that pq only stores unexplored towns, so remove any town
            // from pq that has been explored;
            // pq.pop(); // pops thw node;
        }
        return mind;
    }

    static bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first != b.first){
            return a.first < b.first;
        }
        return a.second > b.second;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> adj[n];
        for(auto val : edges){
            int u = val[0];
            int v = val[1];
            int w = val[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // set<pair<int, int>> st;
        vector<pair<int, int>> va;
        int minc = INT_MAX;
        // int ans = -1;
        for(int node = 0; node < n; node++){
            int count = 0;
            vector<int> vec = dijkstra(node, adj, n);
            // for(auto val : vec){
            //     if(val <= dt){
            //         count++;
            //     }
            // }
            // cout << "this is vec => " << '\n';
            // for(int i = 0; i < n; i++){
            //     cout << i << "-> " << vec[i] << '\n';
            // } cout << '\n';
            for(int i = 0; (i < n); i++){
                if(i==node){continue;}
                if(vec[i] <= dt){
                    count++;
                }
            }
            // cout << "count => " << count << '\n';
            // st.insert({count, node});
            va.push_back({count, node});
            // if(count < minc){
            //     minc = count;
            //     ans = node;
            // }
        }
        sort(va.begin(), va.end(), compare);
        return va[0].second;
        // return ans;
    }
};