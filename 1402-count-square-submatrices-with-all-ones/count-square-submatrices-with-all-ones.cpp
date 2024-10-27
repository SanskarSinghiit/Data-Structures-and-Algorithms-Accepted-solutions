class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            grid[i][0] = matrix[i][0]==1 ? 1 : 0;
        } for(int j = 0; j < n; j++){
            grid[0][j] = matrix[0][j] == 1 ? 1 : 0;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j]==0){continue;}
                int tl = grid[i-1][j-1];
                int up = grid[i-1][j];
                int left=grid[i][j-1];
                grid[i][j]=min({tl,up,left})+1;
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count += grid[i][j];
            }
        } return count;
    }
};