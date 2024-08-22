class Solution {
public:
    int findComplement(int nums) {
        int pow2=0;
        int ans = 0;
        while(nums){
            int x = nums%2;
            if(x==0){
                ans += pow(2,(pow2));
            }
            // cout << "this is x -> " << x << " this is pow2 -> " << pow2 << " this is ans -> " << ans << '\n';
            pow2++;
            nums /= 2;
        }
        return ans;
    }
};