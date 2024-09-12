class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> base;
        for(int i = 0; i < allowed.size(); i++){
            base.insert(allowed[i]);
        }
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            set<char> temp;
            for(int j = 0; j < words[i].size(); j++){
                temp.insert(words[i][j]);
            }
            // cout << "this is temp -> ";
            // for(auto val : temp){cout << val << ' ';} cout << '\n';
            bool check = true;
            for(auto val : temp){
                if(base.find(val) == base.end()){check=false; break;}
            }
            if(check){count++;}
        }
        return count;
    }
};