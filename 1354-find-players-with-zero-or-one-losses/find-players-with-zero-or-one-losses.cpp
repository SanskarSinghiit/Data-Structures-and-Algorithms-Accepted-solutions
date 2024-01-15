class Solution {
public:

    void in(map<int,int>& mp, int x){
        if(mp.find(x)==mp.end()){
            mp.insert({x, 1});
        }
        else{
            mp[x]++;
        }
    }

    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        // set<int> sa;
        map<int,int> ma;
        map<int,int> mb;
        int n = matches.size();
        for(int i = 0; i < n; i++){
            in(ma, matches[i][0]);
            in(mb, matches[i][1]);
        }
        vector<int> list1, list2;
        for(auto val : ma){
            if(mb.find(val.first)==mb.end()){
                list1.push_back(val.first);
            }
        }
        for(auto val : mb){
            if(val.second == 1){
                list2.push_back(val.first);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(list1);
        ans.push_back(list2);
        return ans;
    }
};