class Solution {
public:
    string smallestString(string str) {
        int n = str.size();
        bool notA = false;
        string ans = "";
        int i = 0;
        for(; i < n; i++){
            if(str[i]!='a'){notA = true;}
            if(notA == false){
                if(str[i]=='a'){
                    ans.push_back('a');
                } else{
                    ans.push_back(str[i]-1);
                    notA = true;
                }
            } else{
                if(str[i]=='a'){break;}
                ans.push_back(str[i]-1);
                // else{continue;}
            }
        }
        while(i < n){
            ans.push_back(str[i++]);
        }
        if(notA == false){
            char c = ans.back();
            ans.pop_back();
            ans.push_back('z');
        }
        return ans;
    }
};