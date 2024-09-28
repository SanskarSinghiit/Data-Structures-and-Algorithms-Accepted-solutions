class Solution {
public:

    int f(int amount, int dp[], vector<int>& coins){
        if(amount==0){return dp[amount]=0;}
        if(amount<0){return INT_MAX;}
        if(dp[amount]!=-1){return dp[amount];}
        
        int mini = INT_MAX;
        for(auto val : coins){
            int x = f(amount-val, dp, coins);
            // if(x==-1){continue;}
            if(x<mini){mini=x;}
        }
        if(mini==INT_MAX){
            return dp[amount]=INT_MAX;
        }
        return dp[amount]=1+mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        int dp[100000];
        memset(dp, -1, sizeof(dp));
        int n = coins.size();
        // for(auto val : coins){dp[val]=1;}
        int ans = f(amount, dp, coins);
        return ans==INT_MAX ? -1 : ans;
        // return f(amount, dp, coins) == INT_MAX ? -1 :;
    }
};