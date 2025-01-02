#define pb push_back

class Solution {
public:

    bool is_vowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){return true;}
        return false;
    }

    bool good(string& str){
        if(is_vowel(str[0]) && is_vowel(str[str.size()-1])){return true;}
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n);
        if(good(words[0])){
            prefix[0]=1;
        } else{
            prefix[0]=0;
        }
        for(int i = 1; i < n; i++){
            if(!good(words[i])){prefix[i]=prefix[i-1];}
            else{
                prefix[i]=prefix[i-1]+1;
            }
        }
        vector<int> ans;
        for(auto val : queries){
            int l = val[0]; int r = val[1];
            if(l==0){ans.pb(prefix[r]); continue;}
            else{ans.pb(prefix[r]-prefix[l-1]); continue;}
        }
        return ans;
    }
};