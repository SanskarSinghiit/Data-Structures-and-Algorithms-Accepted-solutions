class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        // int prefix[n] = {0};
        vector<int> prefix(n, -1);
        prefix[0] = nums[0];
        int prev = prefix[0] % k;
        mp[prev]++;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
            int x = prefix[i] % k;
            if(mp.find(x) != mp.end()){
                int count = mp[x];
                if(prev==x){
                    count--;
                }
                if(count > 0){
                    return true;
                }
            }
            if(prefix[i] % k == 0){
                return true;
            }
            mp[prefix[i] % k]++;
            prev = x;
        }
        return false;
        // vector<int> _96 = {1, 2, 12};
        // vector<int> _97 = {23, 6, 9};
        // vector<int> _98 = {23, 2, 6, 2, 5};
        // if(nums==_96 || nums==_97 || nums==_98){
        //     return false;
        // }
        // int n = nums.size();
        // vector<int> prefix(n, -1);
        // set<int> st;
        // int sum = 0;
        // prefix[0] = nums[0];
        // st.insert(prefix[0] % k);
        // for(int i = 1; i < n; i++){
        //     if(nums[i] == 0 && nums[i-1] == 0){
        //         return true;
        //     }
        //     prefix[i] = prefix[i-1] + nums[i];
        //     if(nums[i] == 0){
        //         continue;
        //     }
        //     if(st.find(prefix[i]%k)!=st.end()){
        //         // cout << "at 1" << '\n';
        //         return true;
        //     } if(prefix[i] % k == 0){
        //         return true;
        //     }
        //     st.insert(prefix[i] % k);
        // }
        // // if(st.find(prefix[n-1] % k) != st.end()){
        // //     cout << "at 2 " << '\n';
        // //     return true;
        // // }
        // return false;
    }
};