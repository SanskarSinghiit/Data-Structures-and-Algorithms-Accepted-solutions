class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>> mm;
        int m = arrays.size();
        int i = 0;
        for(auto v : arrays){
            int mini = *min_element(v.begin(), v.end());
            int maxi = *max_element(v.begin(), v.end());
            mm.push_back({mini, i});
            mm.push_back({maxi, i});
            i++;
        }
        sort(mm.begin(), mm.end());
        cout << "this is mm -> " << '\n';
        for(auto val : mm){
            cout << val.first << ' ' << val.second << '\n';
        }
        int lo = 0;
        int hi = mm.size()-1;
        while(lo <= hi){
            if(mm[hi].second != mm[lo].second){
                return mm[hi].first - mm[lo].first;
            } else{
                if(hi-lo==1){return -1;} // since m==1 here, invalid case will never happen ok
                int p = mm[lo+1].first - mm[lo].first;
                int q = mm[hi].first - mm[hi-1].first;
                if(p<q){
                    lo++;
                } else{ // if oth same also then hi--;
                    hi--;
                }
            }
        }
        return -1;
    }
};