class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        map<string, string> mp;
        int n = paths.size();
        for(int i = 0; i < n; i++)
        {
            string a = paths[i][0];
            string b = paths[i][1];
            if(mp.find(a)!=mp.end())
            {
                mp[a]=b;
            }
            else{mp.insert({a, b});}
            if(mp.find(b)==mp.end()){mp.insert({b, "empty"});}
        }
        for(auto val : mp)
        {
            string sec = val.second;
            if(sec=="empty"){return val.first;}
        }
        return "";
    }
};