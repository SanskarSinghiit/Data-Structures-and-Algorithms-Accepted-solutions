class Solution {
public:

    bool check(vector<string>& vec){
        int n = vec.size();
        for(auto val : vec){
            if(!isPalindrome(val)){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(string& str){
        int n = str.size();
        string str1 = "";
        for(int i = n-1; i >= 0; i--){
            str1.push_back(str[i]);
        }
        return str==str1;
    }

    void rec(string& s, vector<string> op, int i, set<vector<string>>& allPartitions, int& count){
        // cout << " i -> " << i << "  ";
        //             for(auto val : op){
        //         cout << val << ' ';
        //     } cout << '\n';
        if(i==0){
            string temp = "";
            temp.push_back(s[0]);
            // op.push_back(string() + s[0]);
            op.push_back(temp);
            rec(s, op, i+1, allPartitions, count);
            return;
        }
        if(i==s.size()){
            if(isPalindrome(op.back()) == false){
                return;
            }
            allPartitions.insert(op);
            // allPartitions.push_back(op);
            // cout << " i->" << i << ' ' << count++ << " => ";
            // for(auto val : op){
            //     cout << val << ' ';
            // } cout << '\n';
            op.clear();
            return;
        }
        op.back().push_back(s[i]);
        rec(s, op, i+1, allPartitions, count);
        op.back().pop_back();
        if(op.back()!="" && isPalindrome(op.back()) == false){
            return;
        }
        string temp = "";
        temp.push_back(s[i]);
        // op.push_back(string() + s[i]);
        op.push_back(temp);
        rec(s, op, i+1, allPartitions, count);
    }

    vector<vector<string>> partition(string s) {
        set<vector<string>> allPartitions;
        // vector<vector<string>> allPartitions;
        vector<vector<string>> ans;
        vector<string> op;
        int count = 0;
        // rec(s, op, 0, allPartitions, count);
        rec(s, op, 0, allPartitions, count);
        // for(auto val : allPartitions){
        //     if(check(val)){
        //         ans.push_back(val);
        //     }
        // }
        for(auto val : allPartitions){
            ans.push_back(val);
        }
        return ans;
    }
};

/*

=> All individual letters are palindromes
=> Call a recursive function to generate all possible partitioning of the given string
=> Store all partitionings somewhere and extract all partitioning which are palindrome 

*/