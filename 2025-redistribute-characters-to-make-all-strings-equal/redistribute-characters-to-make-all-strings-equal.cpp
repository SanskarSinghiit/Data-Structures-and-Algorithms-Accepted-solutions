class Solution {
public:
    bool makeEqual(vector<string>& words)
    {
        int n = words.size();
        if(n==1){return true;}
        map<char,int> mp;
        for(int i = 0; i < n; i++)
        {
            int m = words[i].size();
            for(int j = 0; j < m; j++)
            {
                char c = words[i][j];
                if(mp.find(c)==mp.end()){mp.insert({c, 1});}
                else{
                    mp[c]++;
                }
            }
        }
        // int equal = (*mp.begin()).second;
        // if(equal < n){return false;}
        for(auto val : mp)
        {
            // cout << val.first << " " << val.second << '\n';
            int x = val.second;
            // if(x!=equal){return false;}
            // if(x<n){return false;}
            if(x%n!=0){return false;}
        }
        return true;
    }
};