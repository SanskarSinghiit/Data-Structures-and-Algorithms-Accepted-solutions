class Solution {
public:
    int maxScore(string s)
    {
        int n = s.size();
        int znot = 0;
        int onot = 0;
        for(int i = 0; i < n; i++) 
        {
            if(s[i]=='0'){znot++;}
            else{onot++;}
        }
        string sub = "";
        sub.push_back(s[0]);
        int zero = 0;  // counts LHS zeros
        int ones = onot;  // counts RHS ones
        if(s[0]=='0'){zero++;}
        else{ones--;}
        // int maxi = max(zero, ones);
        int maxi = 0;
        int sum = zero+ones;
        if(sum>maxi){maxi=sum;}
        for(int i = 1; i < n - 1; i++)
        {
            if(s[i]=='0'){zero++;}
            else{ones--;}
            sum = zero+ones;
            if(sum>maxi){maxi=sum;}
        }
        return maxi;
    }
};