class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, -1);
        int count = 0;
        map<int, int> mp;
        prefix[0] = nums[0];
        mp[prefix[0]]++;
        if(prefix[0] == k){
            count++;
        }
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
            if(prefix[i] == k){
                count++;
            } 
            if(mp.find(prefix[i] - k) != mp.end()){
                count+=mp[prefix[i]-k];
            } 
            mp[prefix[i]]++;
        }
        return count;
    }
};


/*  THIS CODE IS OF O(N^2), 
    HWO TO DO IT IN O(NLOGN)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                if(i==0){
                    sum = prefix[j];
                } else{
                    sum = prefix[j] - prefix[i-1];
                }
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};  */


// class Solution {
// public:

//     void print(int arr[], int n){
//         for(int i = 0; i < n; i++){
//             cout << arr[i] << ' ';
//         } cout << '\n';
//     }
// // THIS CODE DOES IT IN O(N^2), USING PREFIX SUM
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int prefix[n];
//         prefix[0] = nums[0];
//         for(int i = 1; i < n; i++){
//             prefix[i] = prefix[i-1] + nums[i];
//         }
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = i; j < n; j++){
//                  int sum = 0;
//                 if(i==0){
//                     sum = prefix[j];
//                 } else{
//                     sum = prefix[j] - prefix[i-1];
//                 }

//                 if(sum == k){
//                     count++;
//                 }
//                 // cout << "sum => " << sum << '\n';
//             }
//         }
//         return count;
//     }
// };