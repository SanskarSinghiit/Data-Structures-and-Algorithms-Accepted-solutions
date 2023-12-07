class Solution {
public:
    string largestOddNumber(string num)
    {
        string ans = "";
        int n = num.size();
        bool noodd = true;
        for(int i = n-1; i >= 0; i--)
        {
            int x = num[i]-'0';
            if((x&1)==true)
            {
                ans = num.substr(0, i+1);
                break;
            }
        }
        return ans;
    }
};