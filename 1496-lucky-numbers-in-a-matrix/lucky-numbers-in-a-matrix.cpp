class Solution {
public:

    bool isLucky(int x, int y, vector<vector<int>>& mat){
        int minr = INT_MAX;
        int n = mat.size();
        int m = mat[0].size();
        for(int j = 0; j < m; j++){
            if(mat[x][j] < minr){
                minr = mat[x][j];
            }
        }
        // cout << "this is minr => " << minr << '\n';
        int maxc = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][y] > maxc){
                maxc = mat[i][y];
            }
        }
        if(minr == maxc && minr == mat[x][y]){
            return true;
        }
        return false;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isLucky(i, j, matrix)){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};