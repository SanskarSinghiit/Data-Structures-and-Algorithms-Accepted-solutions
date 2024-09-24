// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for(int i = m-1; i>=0;i--){
//             for(int j = n-1; j>=0;j--){
//                 if(i==m-1){continue;}
//                 int a = (j-1>=0) ? matrix[i+1][j-1] : INT_MAX;
//                 int b = matrix[i+1][j];
//                 int c = (j+1<n) ? matrix[i+1][j+1] : INT_MAX;
//                 matrix[i][j] += min({a, b, c});
//             }
//         }
//         return *min_element(matrix[0].begin(), matrix[0].end());
//     }
// };




class Solution {
public:

    int f(int r, int i, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        if(i<0||i>=m){return INT_MAX;}
        if(r==n-1){return dp[r][i]=matrix[r][i];}
        if(dp[r][i]!=INT_MIN){return dp[r][i];}
        return dp[r][i] = matrix[r][i]+min({f(r+1, i-1, dp, matrix), f(r+1, i, dp, matrix), f(r+1, i+1, dp, matrix)});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        // -1 means that this value is not been explored yet;
        int minv = INT_MAX;
        for(int i = 0; i < m; i++){
            int x = f(0, i, dp, matrix);
            if(x < minv){
                minv=x;
            }
        }
        return minv;
    }
};