class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, -1);
        map<int, int> mp;
        int count = 0;
        prefix[0] = nums[0];
        // cout << "prefix[0] % k => ";
        // cout << prefix[0] % k << '\n';
        if(prefix[0] % k < 0){
            mp[(prefix[0] % k + k)]++;
        } else{
            mp[prefix[0] % k]++;
        }
        if(prefix[0] % k == 0){
            count++;
        }
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
            int x = prefix[i] % k;
            if(x < 0){
                x = x+k;
            }
            if(mp.find(x) != mp.end()){
                count += mp[x];
            }
            if(x==0){
                count++;
            }
            mp[x]++;
        }
        return count;
        // int n = nums.size();
        // // int prefix[n] = {-1};
        // vector<int> prefix(n, -1);
        // int count = 0;
        // prefix[0] = nums[0];
        // for(int i = 1; i < n; i++){
        //     prefix[i] = prefix[i-1] + nums[i];
        // }
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         int sum = -1;
        //         if(i==0){
        //             sum = prefix[j];
        //         } else{
        //             sum = prefix[j] - prefix[i-1];
        //         }
        //         // cout << i << ' ' << j << " => " << sum << '\n';
        //         if(sum % k == 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};