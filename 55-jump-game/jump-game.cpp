class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){return true;}
        int currVal = 0;
        for(int i = 0; i < n-1; i++){
            currVal = max(currVal, nums[i]);
            if(currVal==0){
                return false;
            }
            currVal--;
        }
        return true;
    }
};