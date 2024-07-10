class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(auto val : logs){
            if(val=="../"){
                count=max(count-1, 0);
            } else if(val=="./"){
                continue;
            } else{
                count++;
            }
        }
        return count;
    }
};