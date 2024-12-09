class Solution {
public:

    bool same_parity(int x, int y){
        if(x%2==0 && y%2==0){return true;}
        else if(x%2==1 && y%2==1){return true;}
        return false;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        // if two particular pair of adjacent elements are not special
        // if they are in the range then the range is not special 
        int n = nums.size(); int q = queries.size();
        // n<=1e5; // q<=1e5;
        // nums[i]<=1e5;
        // find answer of the query in O(1) or at max O(log(N))
        vector<int>prefix(n,0);
        prefix[0]=0;
        for(int i = 1; i < n; i++){
            if(same_parity(nums[i],nums[i-1])){
                prefix[i] = prefix[i-1]+1;
            } else{
                prefix[i]=prefix[i-1];
            }
        }
        // cout << "this is prefix -> " << '\n';
        // for(auto val : prefix){
        //     cout << val << ' ';
        // } cout << '\n';
        vector<bool> ans(q, false);
        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(prefix[l]==prefix[r]){ans[i]=true; continue;}
            else{ans[i]=false; continue;}
        } return ans;
    }
};