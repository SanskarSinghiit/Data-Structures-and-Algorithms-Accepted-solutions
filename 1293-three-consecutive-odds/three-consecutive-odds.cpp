class Solution {
public:

    bool check(vector<int>& arr, int i, int j, int k){
        if((arr[i] & 1) && (arr[j] & 1) && (arr[k] & 1)){
            return true;
        }
        return false;
    }

    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 1;
        for(int k = 2; k < n; k++){
            if(check(arr, i, j, k)){
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
};