class Solution {
public:

    void rec(int num, int sz, vector<int>& ans, int n){
        if(sz==0){ans.push_back(num); return;}
        if(num>n){return;}
        ans.push_back(num);
        num*=10;
        for(int i = 0; i <= 9; i++){
            // int temp = num*10;
            // temp+=i;
            num+=i;
            if(num>n){return;}
            rec(num, sz-1, ans, n);
            num-=i;
        }
    }

    vector<int> lexicalOrder(int n) {
        // bruteforce with extra space
        // vector<string> v;
        // for(int i = 1; i <= n; i++){
        //     v.push_back(to_string(i));
        // }
        // sort(v.begin(), v.end());
        // vector<int> ans;
        // for(auto str : v){
        //     ans.push_back(stoi(str));
        // }

        // optimised with no extra space
        int sz = (int)(log10(n)+1);
        vector<int> ans;
        for(int i = 1; i <= 9; i++){
            if(i>n){break;}
            rec(i, sz-1, ans, n);
        }
        return ans;
    }
};