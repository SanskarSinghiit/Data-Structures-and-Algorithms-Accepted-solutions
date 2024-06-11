class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        int n = arr1.size();
        for(int i = 0; i < n; i++){
            mp[arr1[i]]++;
        }
        vector<int> ans;
        int m = arr2.size();
        for(int i = 0; i < m; i++){
            int x = arr2[i];
            int count = mp[x];
            while(count--){
                ans.push_back(x);
            }
            mp.erase(mp.find(x));
        }
        for(auto val : mp){
            int count = val.second;
            while(count--){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};