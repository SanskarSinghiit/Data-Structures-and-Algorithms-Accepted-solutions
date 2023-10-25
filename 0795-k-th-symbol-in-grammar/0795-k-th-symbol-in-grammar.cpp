class Solution {
public:
    int kthGrammar(long long n, long long k)
    {
         long long a[n]; // stores k value;
    long long b[n]; // stores 0/1 based on prev value;
    a[0] = k;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1]/2 + a[i-1]%2;
    }
    b[n - 1] = 0; // last value always zero;
    // cout << b[n - 1] << endl;
    for (int i = n - 1; i > 0; i--)   // b.size() - 1 times loop execution, due to the fact that we compare i and i - 1, in i;
    {
        long long ki = a[i];      // initial value from a[]
        long long kf = a[i-1];    // final value (one index less value) from a[]
        if (kf == ki * 2)
        {
            b[i-1] = !b[i];
        }
        else
        {
            b[i-1] = b[i];
        }
    }
        return b[0];
    }
};