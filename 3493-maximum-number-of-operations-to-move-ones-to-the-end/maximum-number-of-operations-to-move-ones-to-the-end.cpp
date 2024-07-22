class Solution {
public:
    int maxOperations(string str) {
        // return -1;
        int n = str.size();
        int islands = 0;
        int moves = 0;
        int zc = 0;
        for(int i = n-1; i >= 0; i--){
            if(str[i] == '0'){
                zc++;
            } else{
                if(zc > 0){
                    islands++; // that many islands of zero, to the left of this "1"
                    zc = 0;
                }
                moves += islands;
            }
        }
        return moves;
    }
};