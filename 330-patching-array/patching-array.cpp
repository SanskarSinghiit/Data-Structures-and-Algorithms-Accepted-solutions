class Solution {
public:

    int minPatches(vector<int> &nums, int n){
        long long coverage = 0;
        int m = nums.size();
        long long patch = 0;
        long long j = 0;
        long long i = 1;
        while(i<=n){
            if ((j < m) && (nums[j] <= i)){
                coverage += nums[j];
                j++;
            }
            else{
                patch++;
                if(coverage == i-1){
                    coverage += i;
                }
                // coverage += i;
            }
            i = coverage + 1;
        }
        return patch;
    }
}; 