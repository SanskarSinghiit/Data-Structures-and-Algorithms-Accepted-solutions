class Solution {
public:
    long long minimumSteps(string str) {
        int n = str.size();
        int ztl=0;
        long long steps = 0;
        for(int i = 0; i < n; i++){
            if(str[i]=='0' && i==0){ztl++;}
            else if(str[i]=='0'){steps+=(i-ztl); ztl++;}
            // else
        } return steps;
    }
};