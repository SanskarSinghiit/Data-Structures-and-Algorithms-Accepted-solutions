#define vv(type) vector<vector<type>>
#define v(type) vector<type>
#define vvi vv(int)
#define vvb vv(bool)
#define vi v(int)
#define vb v(bool)

class Solution {
public:

    // rows -> n, i, x
    // colm -> m, j, y, this is the convention I follow, 

    void dfs(int x, int y, vvi& grid1, vvi& grid2, int m, int n, int dx[], int dy[], vvb& vis){
        // if(!valid){return;}
        if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || !grid2[x][y]){return;}
        vis[x][y]=true;
        for(int d = 0; d < 4; d++){
            int cx = x + dx[d];
            int cy = y + dy[d];
            // if(cx < 0 || cx >=n || cy < 0 || cy >= m || vis[cx][cy] || !grid2[cx][cy]){continue;}
            // // if(!grid1[cx][cy]){valid=false; return;}
            // vis[cx][cy]=true;
            dfs(cx, cy, grid1, grid2, m, n, dx, dy, vis);
        } return;
    }
    void check(int x, int y, vvi& grid1, vvi& grid2, int m, int n, int dx[], int dy[], vvb& vis, bool& valid){
        // if(!valid){return;}
        if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || !grid2[x][y]){return;}
        if(!grid1[x][y]){valid=false; return;}
        vis[x][y]=true;
        for(int d = 0; d < 4; d++){
            int cx = x + dx[d];
            int cy = y + dy[d];
            // if(cx < 0 || cx >=n || cy < 0 || cy >= m || vis1[cx][cy] || !grid2[cx][cy]){continue;}
            // if(!grid1[cx][cy]){valid=false; return;}
            // vis1[cx][cy]=true;
            check(cx, cy, grid1, grid2, m, n, dx, dy, vis, valid);
        } return;
    }

    void print(vvb& mat){
        for(auto v : mat){
            for(auto val : v){
                cout << val << ' ';
            } cout << '\n';
        } cout << '\n';
        return;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size(); int m = grid2[0].size();
        vvb vis(n, vb(m, false));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int count = 0;
        int islands = 0;
        // vvb vis1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid2[i][j]){
                    bool valid = true;
                    // vis1 = vis;
                    // dfs(i, j, grid1, grid2, m, n, dx, dy, vis);
                    check(i, j, grid1, grid2, m, n, dx, dy, vis, valid);
                    // cout << "island : " << islands++ << " -> " << " i-> " << i << " j-> " << j << '\n';
                    // print(vis);
                    if(valid){count++;}
                }
            }
        } return count;
    }
};