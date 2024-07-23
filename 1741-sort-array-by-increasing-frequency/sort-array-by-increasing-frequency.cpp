class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        vector<int> f[101];
        for(auto val : nums){
            mp[val]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            int val = it->first;
            int freq = it->second;
            f[freq].push_back(val);
        }
        for(int i = 1; i <= 100; i++){
            vector<int> temp = f[i];
            while(temp.size() > 0){
                for(int j = 0; j < i; j++){
                    ans.push_back(temp.back());
                }
                temp.pop_back();
                // ans.push_back(val);
            }
        }
        return ans;
    }
};