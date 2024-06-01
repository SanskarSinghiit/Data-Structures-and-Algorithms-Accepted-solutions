class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int prev = -1;
        int curr = -1;
        int score = 0;
        prev = int(s[0]);
        for(int i = 1; i < n; i++){
            curr = int(s[i]);
            score += abs(curr - prev);
            prev = curr;
        }
        return score;
    }
};