class Solution {
public:
    int maxProductDifference(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int a = nums.back();
        nums.pop_back();
        int b = nums.back();
        nums.push_back(a);
        int c = nums[0];
        int d = nums[1];
        return a*b - c*d;    
    }
};