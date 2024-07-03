class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = n-1;
        int mindif = INT_MAX;
        for(lo = 0; lo <= 3; lo++){
            hi = lo + n - 4;
            if(lo > hi){
                continue;
            }
            if(nums[hi] - nums[lo] < mindif){
                mindif = nums[hi] - nums[lo];
            }
        }
        return mindif;
    }
};