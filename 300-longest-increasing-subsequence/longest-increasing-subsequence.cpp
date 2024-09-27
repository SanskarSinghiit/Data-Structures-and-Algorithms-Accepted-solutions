class Solution {
public:

    int f(int i, int dp[], vector<int>& nums){
        if(i==0){return 1;}
        if(dp[i]!=-1){return dp[i];}
        int maxi = 0;
        for(int j = i-1; j >= 0; j--){
            if(nums[j] < nums[i]){
                int x = f(j, dp, nums);
                if(x>maxi){maxi=x;}
            }
        }
        return dp[i]=1+maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        int maxi = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            int x = f(i, dp, nums);
            if(x>maxi){maxi=x;}
        }
        // int ans = f(n-1, dp, nums);
        // cout << "this is the dp array -> " << '\n';
        // for(auto val : dp){
        //     cout << val << ' ';
        // } cout << '\n';
        return maxi;
        // return f(n-1, dp, nums);
    }
};