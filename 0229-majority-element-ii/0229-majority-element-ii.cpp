// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums)
//     {
//         vector<int> ans;
//         unordered_set<int> us;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int size = n/3 + 1;
//         int start = 0;
//         int end = size-1;
//         while(end<n)
//         {
//             if(nums[start]==nums[end])
//             {
//                 // ans.push_back(nums[start]);
//                 us.insert(nums[start]);
//             }
//             start++;
//             end++;
//         }
//         for(auto value : us)
//         {
//             ans.push_back(value);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        // First pass to find potential candidates
        for (auto num : nums) {
            if (candidate1 == num) count1++;
            else if (candidate2 == num) count2++;
            else if (count1 == 0) candidate1 = num, count1 = 1;
            else if (count2 == 0) candidate2 = num, count2 = 1;
            else count1--, count2--;
        }
         // Second pass to verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        vector<int> ans;
        if (count1 > nums.size() / 3) ans.push_back(candidate1);
        if (count2 > nums.size() / 3) ans.push_back(candidate2);
        
        return ans;
    }
};