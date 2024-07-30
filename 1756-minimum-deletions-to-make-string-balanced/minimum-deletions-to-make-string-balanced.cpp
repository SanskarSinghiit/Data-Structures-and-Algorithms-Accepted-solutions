class Solution {
public:
    int minimumDeletions(string str) {
        int n = str.size();
        int a[n], b[n];
        int ac = 0;
        int bc = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'a'){
                ac++;
            } else{
                bc++;
            }
            a[i] = ac;
            b[i] = bc;
        }
        if(ac==0 || bc==0){
            return 0;
        }
        int mini = INT_MAX;
        int _1ind = min(ac, bc);
        if(mini > _1ind){
            mini = _1ind;
        }
        for(int i = 0; i < n; i++){
            int acnt = a[i];
            int bcnt = b[i];
            int removed = 0;
            removed += b[i];
            removed += ac - a[i];
            if(removed < mini){
                mini = removed;
            }
        }
        return mini;
    }
};