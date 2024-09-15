class Solution {
public:

    int rec(int i, int dp[], vector<int>& nums, int n, bool firstRobbed, int& times){
        if(dp[i] != -1){return dp[i];}
       if(i==n-1&&firstRobbed){return 0;}

        times++;
        int maxs = 0;
        for(int j = i+2; j < n; j++){
            int sum = rec(j, dp, nums, n, firstRobbed, times);
            maxs=sum>maxs?sum:maxs;
        }
        return dp[i]=nums[i]+maxs;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){return nums[0];}
        if(n==2){return max(nums[0], nums[1]);}
        if(n==3){return max({nums[0], nums[1], nums[2]});}

        int dp[n];
        for(int i = 0; i < n; i++){
            dp[i]=-1;
        }
        // as there can be n options to start from;
        // int maxprofit = -1;
        int times = 0;
        int maxprofit = rec(0, dp, nums, n, true, times);
        dp[n-1]=nums[n-1];
        for(int i = 0; i < n; i++){dp[i]=-1;}
        for(int start = 1; start < n; start++){
            // if(start==0){}
            int sum = 0;
            // if(start==0){
            //     sum = rec(start, dp, nums, n, true, times);
            // } else{
                sum = rec(start, dp, nums, n, false, times);
            // }
            // break;
            // rec(start, dp, nums, n, true);
            // cout << "for start -> " << start << "  this is sum -> " << sum << '\n';
            maxprofit=sum>maxprofit?sum:maxprofit;
        }
        // cout << "times -> " << times << '\n';
        // cout << "after first rec this is dp[] -> " << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << dp[i] << ' ';
        // } cout << '\n';
        return maxprofit;
    }
};