class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-2]!=nums[n-1]){
            return nums[n-1];
        }
        int lo = 0;
        int hi = n-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            // if(mid==0 || mid==n-1){
            //     break;
            // }
            if(nums[mid-1]!= nums[mid] && nums[mid]!= nums[mid+1]){
                return nums[mid];
            }
            else if((nums[mid-1]==nums[mid] && mid%2==0) || (nums[mid]==nums[mid+1] && mid&1)){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return -1;
    }
};