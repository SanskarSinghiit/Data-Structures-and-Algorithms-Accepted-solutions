class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowelCount++;
            }
        }
        if(vowelCount){
            return true;
        }
        return false;
    }
};