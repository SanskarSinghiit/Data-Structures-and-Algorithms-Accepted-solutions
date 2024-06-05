class Solution {
public:

    void print(map<char, int>& mp){
        for(auto val : mp){
            cout << val.first << ' ' << val.second << '\n';
        }
    }

    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        map<char, int> mp;
        string str =  words[0];
        int m = str.size();
        for(int i = 0; i < m; i++){
            mp[str[i]]++;
        }
        for(int i = 1; i < n; i++){
            map<char, int> temp;
            for(auto val : words[i]){
                temp[val]++;
            }
            // cout << "temp map => " << '\n';
            // print(temp);
            // cout << "original map => " << '\n';
            // print(mp);
            map<char, int> mp2 = mp;
            for(auto val : mp2){
                if(temp.find(val.first) == temp.end()){
                    mp.erase(val.first);
                } else if(mp[val.first] != temp[val.first]){
                    int x = mp[val.first];
                    int y = temp[val.first];
                    // cout << " x => " << x << " y => " << y << '\n';
                    // x != y;
                    mp[val.first] = min(x, y);
                }
            }
        }
        vector<string> ans;
        for(auto val : mp){
            int x = val.second;
            while(x--){
            string s = "";
                s.push_back(val.first);
                ans.push_back(s);
            }
        }
        return ans;
    }
};