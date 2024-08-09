class Solution {
public:

    bool isMagical(vector<vector<int>>& vec){
        unordered_set<int> ust;
        for(auto v : vec){
            for(auto val : v){
                if(val > 9 || val < 1){
                    return false;
                }
                ust.insert(val);
            }
        }
        if(ust.size() != 9){
            return false;
        }
        int sum = -1;
        for(int i = 0; i < 3; i++){
            int temp = 0;
            for(int j = 0; j < 3; j++){
                temp += vec[i][j];
            }
            if(sum == -1){
                sum = temp;
            } else if(temp != sum){
                return false;
            }
        }
        for(int j = 0; j < 3; j++){
            int temp = 0;
            for(int i = 0; i < 3; i++){
                temp += vec[i][j];
            }
            if(temp != sum){
                return false;
            }
        }
        int d1 = vec[0][0] + vec[1][1] + vec[2][2];
        int d2 = vec[0][2] + vec[1][1] + vec[2][0];
        if(d1 != sum || d2 != sum){
            return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // vector<vector<int>> vec = {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}};
        // cout << isMagical(vec) << '\n';
        // return -1;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i <= n-3; i++){
            for(int j = 0; j <= m-3; j++){
                vector<vector<int>> vec;
                for(int k = i; k <= i+2; k++){
                    vector<int> temp;
                    for(int l = j; l <= j+2; l++){
                        temp.push_back(grid[k][l]);
                    }
                    vec.push_back(temp);
                }
                if(isMagical(vec)){count++;}
            }
        }
        return count;
    }
};