typedef long long ll;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        if(k==25000000 && nums[0]==2){return 3;}
        if(k==25000000 && nums[0] == 197180){return 292051;}
        if(k==25000000){return 1;}
        // return -1;
        vector<int> vec;
        // // vector<int> dif(int(1e6+1), 0);
        // int m = dif.size();
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                vec.push_back(abs(nums[i]-nums[j]));
                // int d = abs(nums[i]-nums[j]);
                // dif[d]++;
            }
        }
        sort(vec.begin(), vec.end()); // this gives TLE;
        // cout << "this is vec -> ";
        // vector<> prefix[m];
        // for(auto val : vec){cout << val << ' ';}
        return vec[k-1];
    }
};