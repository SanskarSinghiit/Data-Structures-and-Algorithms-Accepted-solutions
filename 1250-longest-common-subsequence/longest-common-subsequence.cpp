class Solution {
public:

    int find(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            return dp[i][j] = 1+find(a, b, i-1, j-1, dp);
        }
        int p = find(a, b, i-1, j, dp);
        int q = find(a, b, i, j-1, dp);
        return dp[i][j] = max(p, q);
    }

    int longestCommonSubsequence(string text1, string text2) {
        string a = text1;
        string b = text2;
        int n = a.size();
        int m = b.size();
        int i = a.size() - 1;
        int j = b.size() - 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = -1;
            }
        }
        return find(a, b, i, j, dp);
    }
};