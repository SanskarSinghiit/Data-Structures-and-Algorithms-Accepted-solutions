class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto p1 = edges[0];
        auto p2 = edges[1];
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];

        if(x1==x2 || x1==y2){
            return x1;
        }
        return y1;
    }
};