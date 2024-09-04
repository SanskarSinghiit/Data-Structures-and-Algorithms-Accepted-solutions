#define vi vector<int>
#define vvi vector<vi>
class Solution {
public:

    bool overlap(int x, int y, int a, int b){
        if(a<=x&&x<=b || a<=y&&y<=b || a>=x&&b<=y || a<=x&&b>=y){return true;}
        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int a = newInterval[0];
        int b = newInterval[1];
        vvi ans;
        vi affected(n, 0);
       if(n==0){ans.push_back({a, b}); return ans;} 
        int k = -1;
        bool affects = false;
        for(int i = 0; i < n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(overlap(x, y, a, b)){
                affected[i]=1;
                affects=true;
                if(k==-1){k=i;}
            }
        }
        bool done=false;
        if(affects==false){
            // ans.push_back({a, b});
            for(int i = 0; i < n; i++){
                int x = intervals[i][0];
                int y = intervals[i][1];
                if(done){
                    ans.push_back(intervals[i]);
                    continue;
                }
                if(x > a){
                    ans.push_back({a, b}); done=true;
                } 
                ans.push_back(intervals[i]);
            }
            if(done==false){
                ans.push_back({a, b});
            }
            return ans;
        }
        // cout << "HI";
        int left = INT_MAX;
        int right = -1;
        for(int i = max(0, k); i < n; i++){
            if(!affected[i]){break;}
            int x = intervals[i][0];
            int y = intervals[i][1];
            left = min({left, x, a});
            right= max({right, y, b});
        }
        bool found = false;
        for(int i = 0; i < n; i++){
            if(!affected[i]){
                ans.push_back(intervals[i]);
            } else{
                if(found){continue;}
                else{
                    ans.push_back({left, right});
                    found=true;
                }
            }
        }
        if(found == false){
            ans.push_back({a, b});
        }
        return ans;
    }
};