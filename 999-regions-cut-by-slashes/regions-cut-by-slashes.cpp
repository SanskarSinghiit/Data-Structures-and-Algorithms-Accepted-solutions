class Solution {
public:

    void dfs(vector<vector<int>>& mat, int px, int py){
        int m = mat.size();  // 3*n, size
        // cout << "dfs -> " << px << ' ' << py << '\n';
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        mat[px][py] = 1;
        for(int i = 0; i < 4; i++){
            int cx = px+dx[i];
            int cy = py+dy[i];
            // cout << "this is cx, cy -> " << cx << ' ' << cy << '\n';
            if(cx<0||cx>=m||cy<0||cy>=m){continue;}
            if(mat[cx][cy]==1){continue;}
            dfs(mat, cx, cy);
        }
    }

    void print(vector<vector<int>>& mat){
        for(auto v : mat){
            for(auto val : v){
                cout << val << ' ';
            } cout << '\n';
        } cout << '\n';
    }

    vector<vector<int>> convert(vector<string>& g){
        int n = g.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            string str = g[i];
            int m = str.size();
            int j = 0;
            // cout << "this is m -> " << m << '\n';
            while(j < m){
                if(str[j] == '/'){
                    temp.push_back(1); j++;
                } else if(str[j] == '\\'){
                    temp.push_back(2); j++;
                } else{
                    temp.push_back(3); j++;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    int regionsBySlashes(vector<string>& g) {
        // string str = g[1];
        // cout << str[0] << ' ' << str[1] << '\n';
        // cout << str.size() << '\n';
        // return -1;
        vector<vector<int>> grid = convert(g);
        int n = g.size();
        vector<vector<int>> mat(3*n, vector<int>(3*n, 0));
        // cout << "this is the grid -> " << '\n';
        // for(auto v : grid){
        //     for(auto val : v){
        //         cout << val << ' ';
        //     } cout << '\n';
        // } cout << '\n';
        // int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < grid[0].size(); j++){
                // cout << i << ' ' << j << '\n';
                if(grid[i][j] == 3){continue;}
                if(grid[i][j] == 1){
                    mat[3*i][3*j+2] = 1;
                    mat[3*i+1][3*j+1]=1;
                    mat[3*i+2][3*j]=1;
                } else if(grid[i][j] == 2){
                    mat[3*i][3*j]=1;
                    mat[3*i+1][3*j+1]=1;
                    mat[3*i+2][3*j+2]=1;
                }
            }
        }
        // cout << "this is the matrix -> " << '\n';
        // for(auto v : mat){
        //     for(auto val : v){
        //         cout << val << ' ';
        //     } cout << '\n';
        // } cout << '\n';
        int components = 0;
        // dfs(mat, 0, 0);
        for(int i = 0; i < 3*n; i++){
            for(int j = 0; j < 3*n; j++){
                if(mat[i][j] == 1){
                    continue;
                } else{
                    components++;
                    dfs(mat, i, j);
                    // cout << "run dfs for " << i << ' ' << j << '\n';
                    // cout << "matrix after this -> " << '\n';
                    // print(mat);
                }
            }
        }
        return components;
        // return -1;
    }
};

/*
    /\\/   
    \\//
       
*/



