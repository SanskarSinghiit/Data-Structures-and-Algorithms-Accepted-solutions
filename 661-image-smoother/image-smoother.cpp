class Solution {
public:

    bool isValid(int x, int y, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(x>=0 && y>=0 && x<m && y<n){return true;}
        return false;
    }

    void change(int i, int j, vector<vector<int>>& img, vector<vector<int>>& grid)
    {
        int sum = 0;
        int cnt = 0;
        for(int x = -1; x <= 1; x++)
        {
            for(int y = -1; y <= 1; y++)
            {
                if(isValid(i+x, j+y, grid)){sum+=grid[i+x][j+y]; cnt++;}
            }
        }
        sum = floor(sum/cnt);
        img[i][j] = sum;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> grid = img;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                change(i,j,img,grid);
            }
        }
        return img;
    }
};