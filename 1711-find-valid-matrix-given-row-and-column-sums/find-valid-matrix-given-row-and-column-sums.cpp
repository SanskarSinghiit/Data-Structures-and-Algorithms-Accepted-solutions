typedef long long ll;
class Solution {
public:


    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> mat(n, vector<int>(m, 0));
        // validate all rows first;
        for(int i = 0; i < n; i++){
            mat[i][0] = rowSum[i];
        }
        // check for each col
        for(int j = 0; j < m; j++){
            ll req = colSum[j];
            ll sum = 0;
            for(int i = 0; i < n; i++){
                sum += mat[i][j];
            }
            ll extra = sum - req;
            for(int i = 0; i < n; i++){
                if(extra > mat[i][j]){
                    mat[i][j+1] = mat[i][j];
                    extra = extra - mat[i][j];
                    mat[i][j] = 0;
                } else if(extra == 0){
                    break;
                }  else if(extra <= mat[i][j]){
                    if(j >= m){
                        // cout << "breaking due to j overflow" << '\n';
                        break;
                    } if(j+1 >= m){
                        // cout << "this is extra => " << extra << "  ";
                        // cout << "j+1 got >= m for j -> " << j << '\n';
                        break;
                    }
                    mat[i][j+1] = extra;
                    mat[i][j] = mat[i][j] - extra;
                    extra = 0;
                } 
            }
        }
        return mat;
    }
};