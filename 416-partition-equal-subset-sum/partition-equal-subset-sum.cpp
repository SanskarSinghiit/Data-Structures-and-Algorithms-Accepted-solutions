class Solution {
public:

    bool rec(int i, int sum, vector<vector<int>>& dp, vector<int>& nums, int n, int target){
        if(i==n && 2*sum==target){return dp[i][sum]=true;}
        if(i==n && 2*sum!=target){return dp[i][sum]=false;}
        if(dp[i][sum]!=-1){return dp[i][sum];}
        return dp[i][sum]=rec(i+1,sum+nums[i],dp,nums,n,target)||rec(i+1,sum,dp,nums,n,target);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int arrsum = 0;
        for(int i = 0; i < nums.size(); i++){arrsum+=nums[i];}
        vector<vector<int>> dp(n+1, vector<int>(20000, -1));
        return rec(0, sum, dp, nums, n, arrsum);
    }
};