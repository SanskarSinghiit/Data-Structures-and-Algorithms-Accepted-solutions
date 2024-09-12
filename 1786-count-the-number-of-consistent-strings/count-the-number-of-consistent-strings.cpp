class Solution {
public:

    void print(int x){
        vector<int> v;
        while(x){
            v.push_back(x%2);
            x /= 2;
        }
        while(v.size() < 26){
            v.push_back(0);
        }
        for(int i = 25; i>= 0; i--){
            cout << v[i] << ' ';
        } cout << '\n';
        return;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int base = 0;
        for(int i = 0; i < allowed.size(); i++){
            int power = allowed[i]-'a';
            // check if it is already there;
            if((base >> power) % 2 == 0){
                base += pow(2, power);
            }
        }
        // cout << "this is base -> " << base << " ";
        int count = 0;
        for(auto str : words){
            int num = 0;
            for(int i = 0; i < str.size(); i++){
                int power = str[i]-'a';
                if((num >> power) % 2 == 0){
                    num += pow(2, power);
                }
            }
            // cout << "this is nums -> " << " ";
            // cout << "this is num||base -> " << (num|base) << " this is base -> " << base << '\n';
            if((num|base) == base){count++;}
        }
        return count;
    }
};



// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//         set<char> base;
//         for(int i = 0; i < allowed.size(); i++){
//             base.insert(allowed[i]);
//         }
//         int count = 0;
//         for(int i = 0; i < words.size(); i++){
//             set<char> temp;
//             for(int j = 0; j < words[i].size(); j++){
//                 temp.insert(words[i][j]);
//             }
//             // cout << "this is temp -> ";
//             // for(auto val : temp){cout << val << ' ';} cout << '\n';
//             bool check = true;
//             for(auto val : temp){
//                 if(base.find(val) == base.end()){check=false; break;}
//             }
//             if(check){count++;}
//         }
//         return count;
//     }
// };