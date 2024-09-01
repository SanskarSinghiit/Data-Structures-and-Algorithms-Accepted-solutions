class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(sz != m*n){return {};}
        vector<vector<int>> _2d(m, vector<int>(n));
        // cout << "original -> " << sz << '\n';
        for(int i = 0; i < sz; i++){
            // cout << i/n << ' ' << i%n  << ' ' << i << '\n';
            _2d[i/n][i%n]=original[i];
            // cout << _2d[i/n][i%n] << '\n';
        } return _2d;
    }
};