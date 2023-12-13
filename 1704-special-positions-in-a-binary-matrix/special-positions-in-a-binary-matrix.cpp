class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        set<pair<int,int>> s;
        int n = mat.size();
        int m = mat[0].size();
        set<int> goodRow, goodCol;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j]==1){cnt++;}
            }
            if(cnt<=1){goodRow.insert(i);}
        }
        for(int j = 0; j < m; j++)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(mat[i][j]==1)
                {
                    cnt++;
                }
            }
            if(cnt<=1){goodCol.insert(j);}
        }


        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j]==1 && goodRow.find(i)!=goodRow.end() && goodCol.find(j)!=goodCol.end())
                {
                    ans++;
                }
            }
        }
    return ans;
    }
};