class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            if(nums[i]==nums[i-1]){
                ans.push_back(nums[i]);
                break;
            }
        }
        int x = 1;
        set<int> st;
        for(int i = 1; i <= n; i++){
            st.insert(i);
        }
        for(int i = 0; i < n; i++){
            auto val = st.find(nums[i]);
            if(val==st.end()){
                continue;
            }
            else{
                st.erase(val);
            }
        }
        ans.push_back(*(st.begin()));
        return ans;
    }
};