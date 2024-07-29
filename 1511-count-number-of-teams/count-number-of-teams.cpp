class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int x = rating[i];
            for(int j = i+1; j < n; j++){
                if(rating[j] < rating[i]){
                    continue;
                }
                for(int k = j+1; k < n;  k++){
                    if(rating[k] < rating[j]){
                        continue;
                    }
                    else{
                        count++;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            int x = rating[i];
            for(int j = i+1; j < n; j++){
                if(rating[j] > rating[i]){
                    continue;
                }
                for(int k = j+1; k < n;  k++){
                    if(rating[k] > rating[j]){
                        continue;
                    }
                    else{
                        count++;
                    }
                }
            }
        }
        return count;
    }
};