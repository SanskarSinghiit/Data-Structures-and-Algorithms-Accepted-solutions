class Solution {
public:

    static bool custom(vector<int>a, vector<int>b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        } return a[1] < b[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), custom);
        int n = intervals.size();
        vector<vector<int>> ans;
        int a = intervals[0][0];
        int b = intervals[0][1];
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(x<=a&&a<=y || a<=x&&y<=b || x<=b&&b<=y || x<=a&&b<=y){
                ans.pop_back();
                ans.push_back({min(a,x), max(b,y)});
            } else{
                ans.push_back(intervals[i]);
            }
            a=ans.back()[0]; b=ans.back()[1];
        }
        return ans;
    }
};