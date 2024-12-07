class Solution {
public:

    bool check(int x, vector<int>& nums, int moves){
        int start = 0;
        while(start<nums.size() && nums[start]<=x){start++;}
        if(start==nums.size()){return true;} // means possible that within moves no. of moves, make everyone <=x
        int count = 0;
        for(int i = start; i < nums.size(); i++){
            int y = nums[i];
            // while(y>x){  // do this in constant time, 
            //     y -= x; count++;
            // }
            int z = y/x;
            if(y%x!=0){z++;}
            z--;
            count += z;
            // cout << "this is the count for " << y << " -> " << count << '\n';
        }
        if(count <= moves){return true;}
        return false;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 1;
        int hi = nums[n-1];
        int mid = lo + (hi-lo)/2;
        int till_best = hi;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2; // mid means, that all numbers are <= mid ? yes or not;
            // cout << "this is mid -> " << mid << '\n';
            if(check(mid,nums,maxOperations)){
                hi = mid-1;
                till_best = min(mid, till_best);
            } else{
                lo = mid+1;
            }
        }
        return till_best;
    }
};