class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        int n = word.size();
        string ans = "";
        while(i < n){
            int count = 1;
            char c = word[i];
            while(i+1 < n && word[i]==word[i+1]){
                count++; i++;
                if(count==9){break;}
            }
            ans.push_back(to_string(count)[0]);
            ans.push_back(c); i++;
        } return ans;
    }
};