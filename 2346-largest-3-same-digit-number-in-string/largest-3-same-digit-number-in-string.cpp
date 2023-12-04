class Solution {
public:
    string largestGoodInteger(string num)
    {
        // vector<char> storeGood;
        int arr[10];
        for(int i = 0; i < 10; i++){arr[i] = 0;}
        int n = num.size();
        int cnt = 1;
        for(int i = 1; i < n; i++)
        {
            char b = num[i]; char a = num[i-1];
            if(b==a){cnt++;}
            if(b!=a){cnt=1;}
            if(cnt==3)
            {
                int x = num[i]-'0';
                // cout << x << '\n';
                arr[x] = 1;
            }
        }
        int i;
        for(i = 9; i>=0; i--)
        {
            if(arr[i]==1)
            {
                // cout << "breaks with : " << i << '\n';
                break;
            }
        }
        if(i==-1){return "";}
        string ans = "";
        string add = to_string(i);
        ans += (add+add+add);
        return ans;
    }
};