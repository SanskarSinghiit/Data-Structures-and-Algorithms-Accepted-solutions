class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        int maxi = 0;
        int count = 0;
        bool change = false;
        for(int i = 0; i < n; i++){
            if(j==n){break;}
            while(count <= k){
                // maxi = j-i+1 > maxi ? j-i+1 : maxi;
                if(nums[j]==0 && change==false){count++;}
                change=false;
                // cout << "A : i->" << i << " j->" << j << " maxi->" << maxi << " count->" << count <<  '\n';
                if(count > k){break;}
                maxi = j-i+1 > maxi ? j-i+1 : maxi;
                j++;
                // cout << "B : i->" << i << " j->" << j << " maxi->" << maxi << " count->" << count <<'\n';
                if(j==n){break;}
                // change=tr;
            }
            // cout << "hi" << '\n';
            if(nums[i]==0){count--;}
            if(count<=k){change=true;}
        }
        return maxi;
    }
};