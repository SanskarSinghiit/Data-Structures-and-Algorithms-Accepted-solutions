class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cntOne = 0;
        for(auto val : nums){
            if(val==1){
                cntOne++;
            }
        }
        int k = cntOne;
        if(k==0){return 0;}
        // apply sliding window template;
        int i = 0;
        int j = 0;
        int zeros = 0;
        while(j-i+1<=k){
            if(nums[j]==0){
                zeros++;
            }
            if(j-i+1==k){break;}
            j++;
        }  // creating the window
        int minSwap = INT_MAX;
        if(zeros < minSwap){
            minSwap = zeros;
        }
          // sliding the window part
        while(j < n){
            if(j+1 == n){
                break;
            }
            if(nums[i] == 0){
                // i++;
                zeros--;
            }
            if(nums[j+1] == 0){
                zeros++;
                // j++;
            }
            if(zeros < minSwap){
                minSwap = zeros;
            }
            i++; j++;
        }
        // circular array sliding window part;
        while(i < n){
            if((i+1) % n == 0){break;}
            if(nums[i]==0){
                zeros--;
            }
            if(nums[(j+1)%n]==0){
                zeros++;
            }
            if(zeros < minSwap){
                minSwap = zeros;
            }
            i++; j++;
        }
        return minSwap;
    }
};