#define v vector

class Solution {
public:

    int f(int i, int j, v<v<int>>& dp, string& s1, string& s2, int n, int m){
        if(i==n || j == m){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(i+1,j+1,dp,s1,s2,n,m);
        }
        return dp[i][j]=max(f(i+1,j,dp,s1,s2,n,m),f(i,j+1,dp,s1,s2,n,m));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(0,0,dp,text1,text2,n,m);
    }
};