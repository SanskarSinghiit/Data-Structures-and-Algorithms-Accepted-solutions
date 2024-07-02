class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(auto val: nums1){
            // st.insert(val);
            mp[val]++;
        }
        int n = nums2.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mp.find(nums2[i]) != mp.end()){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
                if(mp[nums2[i]] == 0){
                    mp.erase(mp.find(nums2[i]));
                }
            }
        }
        return ans;
    }
};