class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int x = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        int q = queries.size();
        int sz = (int)(log2(x)+1);
        vector<vector<int>> v(n, vector<int>(sz, 0));
        for(int i = 0; i < n; i++){
            // if(arr[i])
            // string str = binary_str(arr[i], sz);
            if(i>0){v[i]=v[i-1];}
            // v[i] = v[i-1];
            int y = arr[i];
            for(int j = 0; j < sz; j++){
                // int x = 
                int num = ((y>>(sz-j-1))&1);  // 1 if true, 0 if false;
                v[i][j] += num;
            }
        }
        // cout << "this is the vector -> " << '\n';
        // for(auto vec : v){
        //     for(auto val : vec){
        //         cout << val << ' ';
        //     } cout << '\n';
        // } cout << '\n';
        // // int n = arr.size();
        // // int q = queries.size();
        vector<int> ans;
        // for(int j = 0; )
        for(auto val :  queries){
            int left = val[0];
            int right= val[1];
            // vector<int>
            vector<int> l, r;
            if(left==0){
                int ansvar = 0;
                r=v[right];
                int power = 1;
                for(int i = sz-1; i>=0;i--){
                    if(r[i]&1){
                        ansvar += power;
                        // ans*=10;
                    } power *= 2;
                }
                ans.push_back(ansvar);
            } else{
                int ansvar=0;
                l=v[left-1];
                r=v[right];
                int power=1;
                for(int i = sz-1; i>=0;i--){
                    if((r[i]-l[i])&1){
                        ansvar+=power;
                    }
                    power*=2;
                }
                ans.push_back(ansvar);
            }
        }
        return ans;
    }
};