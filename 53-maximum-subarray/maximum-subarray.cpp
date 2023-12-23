class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int sum = 0;
        int max = 0;
        // handle separately if all negative;
        bool allneg = true;
        for(int i = 0; i < n; i++){if(nums[i]>0){allneg = false; break;}}
        if(allneg){return *max_element(nums.begin(), nums.end());}
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            if(sum < 0){sum=0;}
            if(sum > max){max = sum;}
        }
        return max;
    }
};