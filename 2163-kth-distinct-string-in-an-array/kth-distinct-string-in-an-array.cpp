class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for(auto val : arr){
            mp[val]++;
        }
        for(auto val : arr){
            if(mp[val] == 1){
                k--;
            }
            if(k==0){
                return val;
            }
        }
        return "";
    }
};