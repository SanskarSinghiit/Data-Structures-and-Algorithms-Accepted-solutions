class Solution {
public:
    string removeSpaces(string& s)
    {
        int n = s.size();
        vector<char> v;
        bool foundLetter = false;
        for(int i = 0; i < n-1; i++)
        {
            if(s[i]!=' '){foundLetter=true;}
            if(foundLetter==false){continue;}
            if(s[i]!=' '){v.push_back(s[i]); continue;}
            if(s[i+1]==' '){continue;}
            else{v.push_back(s[i]);}
        }
        if(s[n-1]!=' '){v.push_back(s[n-1]);}
        s="";
        for(int i = 0; i < v.size(); i++){s.push_back(v[i]);}
        v.clear();
        return s;
    }
    
    void reverse(string& s, int i, int j, string& ans)
    {
        for(int k = j; k >= i; k--)
        {
            ans.push_back(s[k]);
        }
        ans.push_back(' ');
        // cout << " ans formed : " << ans << '\n';
    }  

    string reverseWords(string s)
    {
        string ans = "";
        int n = s.size();
        removeSpaces(s);
        // cout<<"s  after removing spaces : " << s << '\n'; 
        n = s.size();
        // cout << "n : " << n << '\n';
        int i = 0; int j = 0;
        string temp = "";
        vector<string> bigDaddy;
        while(i < n && j < n)
        {
            while(s[j]!=' '){temp.push_back(s[j]); j++; if(j>=n){break;}}
            // cout << " j -> " << j << '\n';
            // reverse(s,i,j-1,ans);
            bigDaddy.push_back(temp);
            temp="";
            i=j+1; j=i;
        }
        // cout<<"hi"<<'\n';
        int m = bigDaddy.size();
        for(int i = m-1; i >= 0; i--)
        {
            for(auto value : bigDaddy[i]){ans.push_back(value);}
            ans.push_back(' ');
            // cout<<' ';
        }
        ans.pop_back();
        // cout<<'\n';
        // cout << "hi"<<'\n';
        // cout << "answer size : " << ans.size() << '\n';
        return ans;

    }
};