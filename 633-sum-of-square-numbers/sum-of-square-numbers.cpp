class Solution {
public:

    bool perfectSquare(int x){
        int y = sqrt(x);
        return (y*y==x);
    }

    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            int x = c - i * i;
            if (perfectSquare(x)) {
                return true;
            }
        }
        return false;
    }
};