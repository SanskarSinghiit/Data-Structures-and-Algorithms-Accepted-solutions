class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        int currval = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] > currval){
                currval = nums[i];
            } else if(nums[i] <= currval){
                int diff = currval-nums[i]+1;
                // currval += diff
                count += currval-nums[i]+1;
                nums[i] = currval+1;
                currval = nums[i];
            }
        }
        return count;
    }
};