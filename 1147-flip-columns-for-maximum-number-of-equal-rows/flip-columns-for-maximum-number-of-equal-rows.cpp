class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            int p = -2;
            int ref = matrix[i][0];
            matrix[i][0]=p;
            for(int j = 1; j < n; j++){
                // cout << "this is ref -> " << ref << '\n';
                // cout << "this is matrix[i][j] -> " << matrix[i][j] << '\n';
                if(matrix[i][j]==ref){
                    matrix[i][j]=p;
                } else{
                    matrix[i][j]=-1*p;
                }
            }
        }
        // cout << "this is matrix after modification -> " << '\n';
        // for(auto v : matrix){
        //     for(auto val : v){
        //         cout << val << ' ';
        //     } cout << '\n';
        // } cout << '\n';
        map<vector<int>, int> groups;
        for(int i = 0; i < m; i++){
            groups[matrix[i]]++;
        } 
        // cout << "this is groups map -> " << '\n';
        // for(auto val : groups){
        //     cout << "[";
        //     for(auto vx : val.first){
        //         cout << vx << ", ";
        //     } cout << "], ";
        //     cout << ' ' << val.second << '\n';
        // }
        int maxi = -1;
        for(auto val : groups){
            maxi = max(maxi, val.second);
        }
        // auto it = --(groups.end());
        // int ans = it->second;
        // return ans;
        return maxi;
    }
};