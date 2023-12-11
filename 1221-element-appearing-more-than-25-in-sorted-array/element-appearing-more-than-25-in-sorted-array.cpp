#include <bits/stdc++.h>
class Solution {
public:

        int get(int n)
        {
            int x = n/4;
            double y = n/(4*1.0);
            if(y==(x*1.0))
            {
                return x+1;
            }
            return ceil(y);
        }

    int findSpecialInteger(vector<int>& arr)
    {
        int n = arr.size();
        int sz= get(n);
        int i = 0;
        for(int j = 0; j < n; j++)
        {
            if(j-i+1 < sz){continue;}
            if(arr[i]==arr[j]){return arr[i];}
            i++;
        }
        return -1;
    }
};