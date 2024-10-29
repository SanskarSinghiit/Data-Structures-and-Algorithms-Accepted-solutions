class Solution {
public:

    void dfs(int x, int y, vector<pair<int,int>>& edged, vector<vector<bool>>& vis, int m, int n, int dx[], int dy[], vector<vector<char>>& board){
        for(int i = 0; i < 4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(cx<0||cx>=m||cy<0||cy>=n||vis[cx][cy]||board[cx][cy]=='X'){continue;}
            vis[cx][cy]=true;
            dfs(cx,cy,edged,vis,m,n,dx,dy,board);
        } return;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> edged;
        if(board[0][0]=='O'){edged.push_back({0,0});}
        if(board[m-1][0]=='O'){edged.push_back({m-1,0});}
        if(board[0][n-1]=='O'){edged.push_back({0,n-1});}
        if(board[m-1][n-1]=='O'){edged.push_back({m-1,n-1});}
        for(int i = 1; i < m-1; i++){
            if(board[i][0]=='O'){edged.push_back({i,0});}
            if(board[i][n-1]=='O'){edged.push_back({i,n-1});}
        }
        for(int j = 1; j < n-1; j++){
            if(board[0][j]=='O'){edged.push_back({0,j});}
            if(board[m-1][j]=='O'){edged.push_back({m-1,j});}
        }
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        // vis means O is safe now, connected to an edged
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(auto val : edged){ // making all edged, and their neighbor O's visited
            int x = val.first;
            int y = val.second;
            if(!vis[x][y]){
                vis[x][y]=true;
                dfs(x,y,edged,vis,m,n,dx,dy,board);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        } 
    }
};