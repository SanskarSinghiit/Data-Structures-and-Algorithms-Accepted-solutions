class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x==0)
        {
            return true;
        }
        else if(x < 0)
        {
            return false;
        }
        else
        {
            int size = (int)(log10(abs(x))) + 1;
            int y = (size / 2) - 1;
            int z = x;
            string m = to_string(z);
            for (int i = 0; i <= y; i++)
            {
            // int ten = pow(n, size - 1);
            int j = size - i - 1;
            if (m[i] == m[j])
            {
                continue;
            }
            else
            {
                return false;
            }
            }
            return true;
        }
    }
};