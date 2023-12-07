class Solution {
public:
    string reverseWords(string s)
    {
        string ans = "";
        vector<string> vec;
        int n = s.size();
        string temp = "";
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            if(c!=' ')
            {
                temp.push_back(c);
            }
            else
            {
                if(temp.size() > 0)
                {
                    vec.push_back(temp);
                    temp = "";
                }
            }
        }
        if(temp.size()>0){vec.push_back(temp);}
        int m = vec.size();
        for(int i = m-1; i >= 0; i--)
        {
            ans.append(vec[i]);
            if(i>0){ans.push_back(' ');}
        }
        return ans;
    }
};