class Solution {
public:

    void pushReverse(string& temp, char arr[], int s, int e){
        int n = temp.size();
        while(temp.size() > 0){
            arr[s++] = temp.back();
            temp.pop_back();
        }
    }

    void getSubstr(char arr[], int s, int e, string& temp){
        for(int i = s; i <= e; i++){
            temp.push_back(arr[i]);
        }
    }

    string reverseParentheses(string str) {
        // set<int> st; // stores location of (
        stack<int> stk;
        int n = str.size();
        char arr[2000] = {'#'};
        for(int i = 0; i < n; i++){
            arr[i] = str[i];
        }
        // string temp = "";
        for(int i = 0; i < n; i++){
            if(arr[i] == '('){
                // temp.clear();
                stk.push(i);
            } else if(str[i]==')'){
                // reverseTemp(temp);
                // auto it = --(st.end());
                int pos = stk.top();
                stk.pop();
                // cout << "this is pos => " << pos << '\n';
                // cout << "this is i => " << i << '\n';
                int s = pos+1;
                if(arr[s] == ')'){
                    // stk.pop();
                    continue;
                }
                // cout << "this is s => " << s << '\n';
                int e = i-1;
                // cout << "this is e => " << e << '\n';
                string temp = "";
                getSubstr(arr, s, e, temp);
                // cout << "this is temp => " << temp << '\n';
                pushReverse(temp, arr, s, e);
                // st.erase(it);
            }

        }
        // cout << "this is arr => " << "  ";
        // for(int i = 0; i < n; i++){
        //     cout << arr[i];
        // } cout << '\n';
        string ans = "";
        for(int i = 0; i < n; i++){
            if(arr[i] == '(' || arr[i] == ')'){continue;}
            // cout << arr[i];
            ans.push_back(arr[i]);
        }
        return ans;
    }
};