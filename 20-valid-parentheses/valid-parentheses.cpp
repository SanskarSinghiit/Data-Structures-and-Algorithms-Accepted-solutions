class Solution {
public:

    bool isOpen(char c){
        if(c=='(' || c=='{' || c=='['){
            return true;
        }
        return false;
    }

    bool checkSimilar(char a, char b){
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']')){
            return true;
        } return false;
    }

    bool isValid(string str) {
        int n = str.size();
        stack<char> stk;
        for(int i = 0; i < n; i++){
            char c = str[i];
            // cout << "i->" << i << ' ';
            if(isOpen(c)){
                stk.push(c);
            } else{
                if(stk.empty()){
                    return false;
                }
                char d = stk.top();
                if(checkSimilar(d, c)){
                    stk.pop();
                } else{
                    return false;
                }
            }
            // if(stk.empty()){
            //     cout << "stack got empty" << '\n';
            //     continue;
            // }
            // cout << "top" << stk.top() << '\n';
        }
        cout << stk.size();
        if(stk.size()==0){
            return true;
        }
        return false;
    }
};