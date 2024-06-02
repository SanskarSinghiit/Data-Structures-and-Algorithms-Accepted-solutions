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
};


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