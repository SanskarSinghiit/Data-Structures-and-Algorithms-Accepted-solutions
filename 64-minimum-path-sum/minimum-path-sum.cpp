class Solution {
public:
    int mod = 2*1e9;

    int rec(int x, int y, vector<vector<int>>& dp, vector<vector<int>>&grid, int m, int n){
        if(dp[x][y] != -1){return dp[x][y];}
        int a = INT_MAX;
        int b = INT_MAX;
        if(x+1<m){
            a=rec(x+1, y, dp, grid, m, n);
        }
        if(y+1<n){
            b=rec(x, y+1, dp, grid, m, n);
        }
        return dp[x][y]=grid[x][y]+min(a, b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m-1][n-1]=grid[m-1][n-1];
        return dp[0][0]=rec(0, 0, dp, grid, m, n);
    }
};