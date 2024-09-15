class Solution {
public:

    int f(int n, int dp[]){
        if(dp[n] != -1){return dp[n];}
        return dp[n]=f(n-1, dp)+f(n-2, dp);
    }

    int climbStairs(int n) {
        // int dp[46] = {-1};
        int dp[n+1];
        for(int i = 0; i <= n; i++){
            dp[i]=-1;
        }
        // cout << "this is dp array -> " << '\n';
        dp[0] = dp[1] = 1;
        // cout << "0-> " << dp[0] << "  1-> " << dp[1] << '\n';
        // cout << "2-> " << dp[2] << '\n';
        return f(n, dp);
    }
};