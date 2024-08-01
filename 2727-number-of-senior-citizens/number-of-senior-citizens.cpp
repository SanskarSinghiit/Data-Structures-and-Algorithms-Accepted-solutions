class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int n = details.size();
        for(int i = 0; i < n; i++){
            if(details[i][11] -  '0' > 6){
                count++; continue;
            } else if(details[i][11] - '0' == 6 && details[i][12] - '0' > 0){
                count++; continue;
            } 
        }
        return count;
    }
};