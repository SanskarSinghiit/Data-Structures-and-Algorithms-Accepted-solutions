class Solution {
public:
    int appendCharacters(string s, string t) {
        char curr = t[0];
        int m = t.size();
        int n = s.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            // cout << "s[i] => " << s[i] << '\n';
            // cout << "for i : " << i << " = > " << '\n';
            // cout << "prev curr => " << curr << '\n';
            if(s[i] == curr){
                // cout << "hi";
                if(j==m){
                    // cout << "hi2";
                    return 0;
                    break;
                }
                curr = t[++j];
            }
            // cout << "anew curr => " << curr << '\n';
        }
        return m-j;
    }
};