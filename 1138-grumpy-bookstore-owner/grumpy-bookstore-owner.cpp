class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int score = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                score+=customers[i];
            }
        }
        // cout << "initial score => " << score << '\n';
        int i = 0;
        int j = 0;
        while(j-i+1 <= minutes){
            if(grumpy[j] == 1){
                score += customers[j];
                // cout << "the j => " << j << '\n';
            }
            // cout << "j->" << j << " score->" << score << '\n';
            if(j-i+1 == minutes){
                break;
            } else{
                j++;
            }
        }
        int maxi = -1;
        if(score > maxi){
            maxi = score;
            // cout << "i -> " <</ i << " " << "j -> " << j << " score -> " << score << '\n';
        }
        while(j < n){
            // remove i
            // i++;
            j++;
            if(j==n){
                break;
            }
            if(grumpy[i]){
                score -= customers[i];
            }
            if(grumpy[j]){
                score += customers[j];
            }
            i++;
            // cout << "i -> " << i << " " << "j -> " << j << " score -> " << score << '\n';
            if(score > maxi){
                maxi = score;
            }
        }
        return maxi;
    }
};