class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // first prioritise maximising the bitwise AND value, 
        // then maximise the subarray size,
        int n = nums.size();
        int x = *max_element(nums.begin(), nums.end());
        int count = 1;
        int maxc = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i]==x && nums[i]==nums[i+1]){
                count++;
                if(count>maxc){maxc=count;}
            } else{
                count=1;
            }
        }
        return maxc;
    }
};