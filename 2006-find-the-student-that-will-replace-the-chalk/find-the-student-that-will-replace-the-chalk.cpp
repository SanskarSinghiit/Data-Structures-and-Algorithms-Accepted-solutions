#define ll long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        ll prefix[n];
        prefix[0]=chalk[0];
        for(int i = 1; i < n; i++){
            prefix[i]=prefix[i-1]+chalk[i];
        }
        if(k > prefix[n-1]){
            ll times = k/prefix[n-1];
            k -= times*prefix[n-1];
        }
        // now k is < prefix[n-1];
        // if(k==0){return 0;}
        auto it = upper_bound(prefix, prefix+n, k);
        ll index = it-prefix;
        // if(index==n){return 0;}
        return index%n;

    }
};