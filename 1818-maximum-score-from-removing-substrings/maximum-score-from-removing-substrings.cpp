class Solution {
public:
    bool deleteIndices[100000] = {false};

    void solve(int& score, string& str, int xoy, string& target) {
        stack<int> stk;
        int n = str.size();
        // int score = 0;
        // vector<int> deletedIndices;
        for (int i = 0; i < n; i++) {
            if (str[i] == target[0]) {
                stk.push(i);
                // deleteIndices[i] = true;
            } else if (str[i] == target[1]) {
                if (stk.size() > 0) {
                    // cout << "this is stk.top() => " << stk.top() << '\n';
                    deleteIndices[stk.top()] = true;
                    stk.pop();
                    deleteIndices[i] = true;
                    score += xoy;
                }
            } else{
                while(stk.empty() == false){
                    stk.pop();
                }
            }
        }
    }

    int maximumGain(string s, int x, int y) {
        int n = s.size();
        string target = "";
        int xoy = -1;
        if (x > y) {
            target = "ab";
            xoy = x;
        } else {
            target = "ba";
            xoy = y;
        }
        int score = 0;
        // vector<int> deletedIndices;
        solve(score, s, xoy, target);
        // cout << "this is first score => " << score << '\n';
        // cout << "this is deleted => " << '\n';
        // for(int i = 0; i < n; i++){
        //     if(deleteIndices[i]){
        //         cout << i << " -> " << "deleted" << '\n';
        //     }
        // }
        string str = "";
        int j = 0;
        // int n = s.size();
        for (int i = 0; i < n; i++) {
            if (deleteIndices[i] == false) {
                // j++;
                str.push_back(s[i]);
                // continue;
            }
        }
        // cout << "this is str => " << str << '\n';
        // vector<int> temp;
        // deletedIndices.clear();
        string newTarget = "";
        newTarget.push_back(target.back());
        target.pop_back();
        newTarget.push_back(target.back());
        // cout << "this is newTarget => " << newTarget << '\n';
        solve(score, str, x+y-xoy, newTarget);
        return score;
    }
};