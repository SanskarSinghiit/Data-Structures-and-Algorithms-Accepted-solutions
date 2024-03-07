typedef long long ll;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        ll i = 0, j = 0;
        vector<int> ans;
        set<int> st;
        while(i < n && j < m){
            ll x = nums1[i];
            ll y = nums2[j];
            if(x==y){
                st.insert(x);
                // ans.push_back(x);
                i++;
            } else if(x > y){
                j++;
            } else if(y > x){
                i++;
            }
        }
        for(auto val : st){
            ans.push_back(val);
        }
        // for(auto val : ans){
        //     cout << val << ' ';
        // } cout << '\n';
        return ans;
    }
};