class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        vector<int> xc;
        for(auto value : points)
        {
            xc.push_back(value[0]);
        }
        sort(xc.begin(), xc.end());
        int n = xc.size();
        int dif = 0;
        for(int i = 1; i < n; i++)
        {
            int x = xc[i]-xc[i-1];
            if(x>dif){dif=x;}
        }
        return dif;
    }
};