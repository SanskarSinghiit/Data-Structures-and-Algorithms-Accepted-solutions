class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for(auto val : s){
            if(!stk.empty() && ((stk.top()=='A' &&  val=='B') || (stk.top()=='C' && val=='D'))){stk.pop();}
            else{stk.push(val);}
        } return stk.size();
    }
};