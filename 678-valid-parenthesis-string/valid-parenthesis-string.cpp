class Solution {
public:
    bool checkValidString(string str) {
        int n = str.size();
        stack<int> stk1, stk2;
        for(int i = 0; i < n; i++){
            if(str[i]=='('){
                stk1.push(i);
            } else if(str[i]=='*'){
                stk2.push(i);
            } else{
                // ')' case;
                if(stk1.size() > 0){
                    stk1.pop(); continue;
                } else if(stk2.size() > 0){
                    stk2.pop(); continue;
                } else{return false;}
            }
        }
        if(stk1.size() == 0){return true;}
        while(stk1.size() > 0){
            if(stk2.size()==0){return false;}
            if(stk2.top() < stk1.top()){return false;}
            stk2.pop(); stk1.pop();
        }
        return true;
    }
};