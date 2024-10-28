class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        set<long long> st;
        for(auto val : nums){
            st.insert(val);
        } int maxc = 1;
        for(int i = 0; i < n; i++){
            int count = 1;
            long long x = nums[i]*1LL;
            while(st.find(x*x)!=st.end()){
                count++;
                x = x*x;
            }
            maxc = max(maxc, count);
        } 
        if(maxc==1){return -1;}
        return maxc;
    }
};