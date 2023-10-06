class Solution {
public:

    int func(int n, int k, vector<int>& vec)
    {
        int x = n/k;
        for(int i = 0; i < k; i++)
        {
            // vec.push_back(x);
            vec[i] = x;
        }
        int y = n % k;
        // cout << " y: " << y << '\n';
        // return 0; 
        for(int i = 0; i < y; i++)
        {
            vec[i]++;
        }
        // return 0;
        int product = 1;
        for(int i = 0; i < k; i++)
        {
            product *= vec[i];
        }
        // vec.clear();
        return product;
    }

    int integerBreak(int n)
    {
        // n = 10;
        // int k = 4;
        vector<int> vec(n, 1);
        // cout << func(n, k, vec);
        int maxi = INT_MIN;
        for(int i = 2; i <= n; i++)
        {
            int z = func(n, i, vec);
            maxi = maxi < z ? z : maxi;
        }
        return maxi;
        // return 0;
    }
};