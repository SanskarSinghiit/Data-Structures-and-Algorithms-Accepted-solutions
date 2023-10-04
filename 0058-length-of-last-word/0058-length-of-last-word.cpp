class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        for(int i = 0; i < n/2; i++)
        {
            swap(s[i], s[n-i-1]);
        }
        int cnt = 0;
        bool foundanyletter = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i]!=' '){foundanyletter=true;cnt++;}
            else if(foundanyletter==false)
            {
                continue;
            }
            else{break;}
        }
        return cnt;
    }
};