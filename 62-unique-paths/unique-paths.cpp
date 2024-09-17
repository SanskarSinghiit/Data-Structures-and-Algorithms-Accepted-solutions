class Solution {
public:
    int mod = 2*1e9;

    int rec(int x, int y, vector<vector<int>>& dp, int m, int n){
        if(dp[x][y] != -1){return dp[x][y];}
        int a = 0;
        int b = 0;
        if(x+1<m){
            a = rec(x+1, y, dp, m, n);
        } 
        if(y+1<n){
            b = rec(x, y+1, dp, m, n);
        }
        dp[x][y]=(a%mod + b%mod)%mod;
        // cout << "x->"<< x << ' ' << "y->"<<y<<" dp[x][y]-> " << dp[x][y] << '\n';
        // if(x==2&&y==0&&m==4&&n==4){
        //     cout << "this is 2, 0, and this is dp[3][0] -> " << dp[3][0] << " and dp[2][1] -> " << dp[2][1] << '\n';
        //     cout << "this is a-> " << a << " and this is b -> " << b << '\n';
        //     cout << "this is a_m+b_m_m -> " << (a%m + b%m)%m << '\n';
        // }
        return dp[x][y];
    }

    int uniquePaths(int m, int n) {
        // int dp[m-1][n-1];
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m-1][n-1]=1;
        return dp[0][0] = rec(0, 0, dp, m, n);
    }
};