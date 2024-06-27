class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // auto p1 = edges[0];
        // auto p2 = edges[1];
        // int x1 = p1[0];
        // int y1 = p1[1];
        // int x2 = p2[0];
        // int y2 = p2[1];

        // if(x1==x2 || x1==y2){
        //     return x1;
        // }
        // return y1;
        // guaranteed that a star exists;
        vector<int> edge1 = edges[0];
        vector<int> edge2 = edges[1];
        int n1 = edge1[0];
        int n2 = edge1[1];
        int m1 = edge2[0];
        int m2 = edge2[1];

        if(n1==m1 || n1 == m2){
            return n1;
        }
        return n2;
    }
};