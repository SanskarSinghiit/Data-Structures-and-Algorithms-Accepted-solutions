class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // take transpose
        // 1st col <-> last column
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // cout << "matrix after transpose -> " << '\n';
        // for(auto v : matrix){
        //     for(auto val : v){
        //         cout << val << ' ';
        //     } cout << '\n';
        // } cout << '\n';
        for(int j = 0; j < n/2; j++){
            for(int i = 0; i < n; i++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        } // return matrix;
    }
};