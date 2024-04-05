class Solution {
public:

    bool similar(char a, char b){
        int x = int('a');
        int y = int('A');
        int z = abs(x-y);
        return (abs(int(a) - int(b)) == z);
    }

    string makeGood(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i = 0; i < n; i++){
            if(stk.empty()){
                stk.push(s[i]);
            } else{
                if(similar(stk.top(), s[i])){
                    stk.pop();
                } else{
                    stk.push(s[i]);
                }
            }
        }
        stack<char> stk2;
        string str = "";
        int m = stk.size();
        if(m==0){
            return str;
        }
        for(int i = 0; i < m; i++){
            stk2.push(stk.top());
            stk.pop();
        }
        for(int i = 0; i < m; i++){
            str.push_back(stk2.top());
            stk2.pop();
        }
        return str;
    }
};