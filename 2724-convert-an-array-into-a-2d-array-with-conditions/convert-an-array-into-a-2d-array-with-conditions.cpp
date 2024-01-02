class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(mp.find(x)==mp.end()){
                mp.insert({x, 1});
            }
            else{
                mp[x]++;
            }
        }
        int maxdup = 0;
        for(auto val : mp){
            int x = val.second;
            maxdup = x>maxdup ? x : maxdup;
        }
        // int m = mp.size();
        vector<vector<int>> ans(maxdup);
        for(int i = 0; i < maxdup; i++){  // filling ans[i];
            for(auto val : mp){
                int p = val.first;
                int q = val.second;
                if(q>0){
                    ans[i].push_back(p);
                    mp[p]--;
                }
            }
        }
        return ans;
    }
};