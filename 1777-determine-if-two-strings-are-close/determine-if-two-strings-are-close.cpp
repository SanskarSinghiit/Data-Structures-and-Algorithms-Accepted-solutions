class Solution {
public:

    void in(map<char, int>& mp, char c){
        if(mp.find(c)==mp.end()){
            mp.insert({c, 1});
        }
        else{
            mp[c]++;
        }
    }

    // void print(vector<int> vec){
    //     for(auto val : vec){
    //         cout << val << ' ';
    //     }
    //     cout << '\n';
    // }
    // void print(vector<char> vec){
    //     for(auto val : vec){
    //         cout << val << ' ';
    //     }
    //     cout << '\n';
    // }

    bool closeStrings(string word1, string word2){
        int m = word1.size();
        int n = word2.size();
        if(m!=n){
            return false;
        }
        map<char, int> mp1, mp2;
        for(int i = 0; i < n; i++){
            in(mp1, word1[i]);
        }
        for(int i = 0; i < n; i++){
            in(mp2, word2[i]);
        }
        vector<int> v1, v2;
        vector<char> s1, s2;
        for(auto val : mp1){
            v1.push_back(val.second);
            s1.push_back(val.first);
        }
        for(auto val : mp2){
            v2.push_back(val.second);
            s2.push_back(val.first);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        // cout << s1 << ' ' << s2 << '\n';
        // print(v1); print(v2); print(s1); print(s2);
        return v1==v2 && s1==s2;
    }
};