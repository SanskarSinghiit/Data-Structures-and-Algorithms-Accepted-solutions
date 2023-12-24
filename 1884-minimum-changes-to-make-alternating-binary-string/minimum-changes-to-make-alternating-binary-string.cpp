class Solution {
public:

    string fillOption(bool x, string& str, int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(x==false)
            {
                str.push_back('0');
            }
            else{
                str.push_back('1');
            }
            x = !(x);
        }
        return str;
    }

    int cntOnesAfterXor(string& s, string& str)
    {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int x = s[i] - '0';
            int y = str[i] - '0';
            int z = x^y;
            if(z==1){cnt++;}
        }
        return cnt;
    }

    int minOperations(string s)
    {
        int n = s.size();
        string op1 = ""; // 010101 format
        string op2 = ""; // 101010 format
        fillOption(false, op1, n);
        fillOption(true, op2, n);
        cout << "option 1 : " << op1 << '\n' << "option 2 : " << op2 << '\n';
        int x = cntOnesAfterXor(s, op1);
        int y = cntOnesAfterXor(s, op2);
        return min(x, y);
    }
};