class Solution {
public:

    int func(int n, int k)
    {
        int x = n/k; // the base numbers;
        int y = n%k; // the extras;
        int product = 1;
        for(int i = 0; i < k; i++)
        {
            if(y>0)
            {
                product *= (x+1); y--;
            }
            else
            {
                product *= x;
            }
        }
        return product;
    }

    int integerBreak(int n)
    {
        int maxi = INT_MIN;
        for(int i = 2; i <= n; i++)
        {
            int z = func(n, i);
            maxi = maxi < z ? z : maxi;
        }
        return maxi;
    }
};