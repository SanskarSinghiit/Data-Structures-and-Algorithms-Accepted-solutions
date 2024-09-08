class Solution {
public:
    // so the best approach is do a left pass, and finalise all increasing seq;

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1); // 0 means unassigned
        for(int i=1; i <n; i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }for(int i = n-2; i >= 0; i--){
            if(ratings[i]>ratings[i+1]){
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }
        int candies=0;
        for(auto val : candy){candies+=val;}
        return candies;
        
    }
};