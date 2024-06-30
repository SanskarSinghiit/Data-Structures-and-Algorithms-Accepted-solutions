class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), greater<vector<int>>());
        // input(edges);
        DisjointSet A(n), B(n);
        int edgesUsed = 0;
        int counterA = n;
        int counterB = n;
        for(auto vec : edges){
            int type = vec[0];
            int u = vec[1];
            int v = vec[2];
            if(type==3){
                bool edgeAdded = false;
                if(A.findUPar(u) != A.findUPar(v)){
                    edgeAdded = true;
                    A.unionByRank(u, v);
                    counterA--;
                }
                if(B.findUPar(u) != B.findUPar(v)){
                    edgeAdded = true;
                    B.unionByRank(u, v);
                    counterB--;
                }
                if(edgeAdded){
                    edgesUsed++;
                }
            } else if(type==2){
                if(B.findUPar(u) != B.findUPar(v)){
                    B.unionByRank(u, v);
                    edgesUsed++;
                    counterB--;
                }
            } else if(type==1){
                if(A.findUPar(u) != A.findUPar(v)){
                    A.unionByRank(u, v);
                    edgesUsed++;
                    counterA--;
                }
            }
        }
        // cout << "counterA => " << counterA << "  counterB => " << counterB << "  edgesUsed => " << edgesUsed << '\n';
        if(counterA == counterB && counterB == 1){
            // cout << edges.size() - edgesUsed << '\n';
            return edges.size()-edgesUsed;
        }
        return -1;
    }
};