class Solution {
public:

    int findCount(string& str){
        int n = str.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(str[i]=='1'){
                count++;
            }
        }
        return count;
    }

    int numberOfBeams(vector<string>& bank)
    {
        int n = bank.size();
        vector<int> numb(n,0);
        for(int i = 0;i < n; i++){
            numb[i] = findCount(bank[i]);
        }
        vector<int> candidates;
        for(int i = 0; i < n; i++){
            if(numb[i]>0){
                candidates.push_back(numb[i]);
            }
        }
        int answer = 0;
        int m = candidates.size();
        if(m<2){return 0;}
        int first = candidates[0], second = candidates[1];
        for(int i = 1; i < m; i++){
            first = candidates[i-1];
            second = candidates[i];
            answer += (first*second);
        }
        return answer;
    }
};