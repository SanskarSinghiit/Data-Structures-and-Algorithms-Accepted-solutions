#define vvi vector<vector<int>>

class Solution {
public:

    // vis if a pixel has color == color, 

    void rec(int x, int y, int color, int scolor, vvi& image, vvi& ans, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m || image[x][y]!=scolor || ans[x][y]!=-1){return;}
        ans[x][y]=color;
        int dx[4]={0, 1, 0, -1};
        int dy[4]={-1, 0, 1, 0};
        for(int i = 0; i < 4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];
            rec(cx, cy, color, scolor, image, ans, n, m);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int scolor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1)); // -1 is unvisited
        rec(sr, sc, color, scolor, image, ans, n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ans[i][j]==-1){ans[i][j]=image[i][j];}
            }
        }
        return ans;
    }
};