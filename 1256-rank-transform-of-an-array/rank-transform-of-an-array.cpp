class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        int rank=1;
        for(auto val : nums){
            if(mp.find(val)==mp.end()){
                mp[val]=rank++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        } return ans;
    }
};