class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int onesRow[m], onesCol[n], zeroRow[m], zeroCol[n];
        for(int i = 0; i < m; i++)
        {
            int cntones = 0;
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j]==1){cntones++;}
            }
            onesRow[i]=cntones;
            zeroRow[i]=m-cntones;
        }
        for(int j = 0; j < n; j++)
        {
            int cntones = 0;
            for(int i = 0; i < m; i++)
            {
                if(grid[i][j]==1){cntones++;}
            }
            onesCol[j]=cntones;
            zeroCol[j]=n-cntones;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                grid[i][j]=onesRow[i]+onesCol[j]-zeroRow[i]-zeroCol[j];
            }
        }
        return grid;
    }
};