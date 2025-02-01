class Solution {
public:
    bool isEven(int x){
        return (x%2 == 0);
    }

    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(isEven(nums[i-1]) == !isEven(nums[i])){
                continue;
            }
            return false;
        }
        return true;
    }
};