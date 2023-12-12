class Solution {
public:
    int climbStairs(int n)
    {
        if(n<=2){return n;}
        int lo = 1, hi = 2;
        int curr;
        for(int i = 3; i <= n; i++)
        {
            curr = lo+hi;
            lo=hi;
            hi=curr;
        }
        return curr;
    }
};