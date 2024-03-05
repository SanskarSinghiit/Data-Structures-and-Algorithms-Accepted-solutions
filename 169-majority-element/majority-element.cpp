class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
// '        // if(n==2){
//         //     return nums[1];
//         // }'
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};