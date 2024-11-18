class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n,0);
        if(k==0){return ans;}
        for(int i = 0; i < n; i++){
            // for(int j = i+1 ; j <)
            int count = 0; int j = k>0 ? (i+1) : (i-1);
            int sum = 0;
            while(count < abs(k)){
                int x = code[((j+n) % n)];
                sum += x;
                // cout << "this is x -> " << x << "  this is j -> " << j << '\n';
                j = k>0 ? j+1 : j-1;
                count++;
            }
            ans[i] = sum;
            // break;
        } return ans;
    }
};