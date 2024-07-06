class Solution {
public:
    int passThePillow(int n, int time) {
        int final = time % (2*(n-1));
        if(final <= n-1){
            return final + 1;
        } else{
            return 2*n - final - 1;
        }
        return -1; // never gonna happen
    }
};