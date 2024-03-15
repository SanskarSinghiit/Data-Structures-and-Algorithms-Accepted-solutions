class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int product = 1;
        product *= nums[0];
        int ans = 0;
        // cout << " i->" << i << " j->" << j << " product->" << product << " ans->" << ans << '\n';
        while(i < n && j < n && i <= j){
            if(product >= k){
                if(j-i+1==1){
                    product /= nums[i++];
                    j++;
                    product *= nums[j];
                    // continue;
                } else{
                    product /= nums[i++];
                }
                // continue;
            } else{
                ans += j-i+1;
                j++;
                if(j==n){break;}
                product *= nums[j];
            }
            // cout << " i->" << i << " j->" << j << " product->" << product << " ans->" << ans << '\n';
        }
        return ans;
    }
};