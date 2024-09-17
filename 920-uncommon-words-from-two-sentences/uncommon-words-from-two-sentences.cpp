class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        string str = "";
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == ' ' && str.size() > 0){
                mp[str]++;
                str="";
            } else{
                str.push_back(s1[i]);
            }
        } if(str.size()>0){
            mp[str]++; str="";
        }
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] == ' ' && str.size() > 0){
                mp[str]++;
                str="";
            } else{
                str.push_back(s2[i]);
            }
        } if(str.size()>0){
            mp[str]++; str="";
        }
        // cout << "this is the map -> " << '\n';
        // for(auto val : mp){
        //     cout << val.first << ' ' << val.second << '\n';
        // } cout << '\n';
        vector<string> ans;
        for(auto val : mp){
            if(val.second == 1){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};