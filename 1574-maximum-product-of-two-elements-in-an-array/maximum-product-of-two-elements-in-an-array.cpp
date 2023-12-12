class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; i++){nums[i]-=1;}
        int maxi = INT_MIN;
        int sec = INT_MIN+1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i]>maxi)
            {
                sec=maxi; maxi=nums[i];
                // cout << "maxi -> " << maxi << '\n';
                // cout << "sec ->  " << sec << '\n';
            }
            else if(nums[i]>sec)
            {
                sec=nums[i];
            }
        }
        // cout << "maxi -> " << maxi << '\n';
        // cout << "sec ->  " << sec << '\n';
        return maxi*sec; 
    }
};