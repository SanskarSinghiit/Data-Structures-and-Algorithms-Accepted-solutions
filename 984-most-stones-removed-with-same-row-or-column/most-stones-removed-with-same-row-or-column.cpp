// // #define vv(type) vector<vector<type>>
// // #define vvvv(type) vector<vector<vector<vector<type>>>>
// // #define vvi vv(int)
// // #define vvvvi vvvv(int)


// class Solution {
// public:

//     void rec(map<vector<int>, bool>& vis, map<vector<int>, vector<vector<int>>>& mp, vector<int>& v){
//         // count++;
//         // int r = v[0]; int c = v[1];
//         if(vis[v]){return;}
//         vis[v] = true;
//         for(auto c : mp[v]){
//             // int cx=c[0]; int cy=c[1];
//             if(!vis[c]){
//                 rec(vis, mp, c);
//             }
//         }
//     }

//     // bool cs(vector<int>a, vector<int>b){
//     //     if(a[0] != b[0]){
//     //         return a[0]<b[0];
//     //     } return a[1]<b[1];
//     // }

//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         // sort(stones.begin(), stones.end());
//         // return -1;
//         // vector<vector<vector<vector<int>>>> adj(10001, vector<vector<vector<int>>>(10001));
//         map<vector<int>, vector<vector<int>>> mp;
//         for(auto v : stones){
//             int x=v[0]; int y=v[1];
//             for(auto v1 : stones){
//                 if(v1[0]==v[0] && v1[1]==v[1]){continue;}
//                 // int x1=v1[0]; int y1=v1[1];
//                 if(v1[0]==v[0]||v1[1]==v[1]){
//                     mp[v].push_back({v1[0], v1[1]});
//                 }
//             }
//         }
//         // return -1;
//         // vector<vector<bool>> vis(10001, vector<bool>(10001, false));
//         map<vector<int>, bool> vis;
//         for(auto val : stones){
//             vis[val]=false;
//         }
//         // int count = 0;
//         // int ans = 0;
//         // cout << "this is the map -> " << '\n';
//         // for(auto it = mp.begin(); it != mp.end(); it++){
//         //     auto key = it->first;
//         //     auto value=it->second;
//         //     cout << key[0] << ' ' << key[1] << "  ->  " << "{";
//         //     for(auto vec : value){
//         //         cout << "{" << vec[0] << ", " << vec[1] << "}, ";
//         //     } cout << "}" << '\n';
//         // }
//         // return -1;
//         int connected = 0;
//         for(auto v : stones){
//             if(vis[v] == false){
//                 rec(vis, mp, v);
//                 // cout << "this is count -> " << count << '\n';
//                 // ans = ans + (count-1);
//                 connected++;
//                 // count=0;
//             }
//         }
        
//         return n-connected;
//     }
// };
class Solution {
private:
    int connectedComponentCount = 0;

    int findRepresentative(int element, vector<int>& setRepresentatives) {
        if (setRepresentatives[element] == 0) {
            setRepresentatives[element] = element;
            connectedComponentCount++;
        }
        return setRepresentatives[element] == element ? element : 
               (setRepresentatives[element] = findRepresentative(setRepresentatives[element], setRepresentatives));
    }

    void mergeComponents(int elementA, int elementB, vector<int>& setRepresentatives) {
        int repA = findRepresentative(elementA, setRepresentatives);
        int repB = findRepresentative(elementB, setRepresentatives);
        if (repA != repB) {
            setRepresentatives[repB] = repA;
            connectedComponentCount--;
        }
    }

public:
    int removeStones(vector<vector<int>>& stonePositions) {
        vector<int> setRepresentatives(20003, 0);
        for (const auto& stonePosition : stonePositions) {
            mergeComponents(stonePosition[0] + 1, stonePosition[1] + 10002, setRepresentatives);
        }
        return stonePositions.size() - connectedComponentCount;
    }
};

