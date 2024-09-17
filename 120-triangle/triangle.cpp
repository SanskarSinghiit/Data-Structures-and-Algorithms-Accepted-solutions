class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for(int i = m-1; i>=0; i--){
            int n = triangle[i].size();
            for(int j = 0; j < n; j++){
                if(i==m-1){continue;}
                triangle[i][j]+=min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};