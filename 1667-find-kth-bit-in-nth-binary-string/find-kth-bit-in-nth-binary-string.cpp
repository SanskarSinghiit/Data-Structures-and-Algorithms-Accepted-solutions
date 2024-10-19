class Solution {
public:

    bool f(int n, int k){
        // cout << "k -> " << k << '\n';
        if(n==1){return false;}
        if(k==(n/2)+1){return true;}
        if(k<=n/2){return f(n/2, k);}
        return !f(n/2,n-k+1);
    }
    char findKthBit(int n, int k) {
        int sz = 1;
        for(int i = 2; i <= n; i++){sz = 2*sz+1;}
        // cout << "this is the size -> " << sz << '\n';
        return f(sz,k) ? '1' : '0';
    }
};