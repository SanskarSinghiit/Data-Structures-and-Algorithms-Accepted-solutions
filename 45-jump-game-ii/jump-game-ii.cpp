class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int range = i+nums[0];
        int jumps = 0;
        while(i < n){
            if(i==n-1){return jumps;}
            if(range>=n-1){return jumps+1;}
            int maxi=-1;
            int maxind=-1;
            for(int j = i+1; j <= range; j++){
                int x = j+nums[j];
                if(x>maxi){
                    maxi=x;
                    maxind=j;
                }
            }
            if(maxi<=range){return -1;}
            range=maxi;
            i=maxind;
            jumps++;
        }
        return jumps;
    }
};