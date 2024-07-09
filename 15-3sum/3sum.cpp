class Solution {
public:

    vector<vector<int>> twoSum(int target, int start, int n, vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> temp;
        int i = start;
        int j = n-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum > target){
                j--;
            } else if(sum < target){
                i++;
            } else{
                while(i < n-1 && nums[i] == nums[i+1]){
                    i++;
                }
                while(j>1 && nums[j] == nums[j-1] ){
                    j--;
                }
                temp.push_back(-1*target);
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                i++;
                j--; 
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int x = nums[i];
            vector<vector<int>> temp = twoSum(-1*x, i+1, n, nums);
            if(temp.empty()){
                continue;
            }
            // sort(temp.begin(), temp.end());
            // ans.push_back(temp);
            for(auto val : temp){
                ans.push_back(val);
            }
            // st.insert(temp);
        }
        // set<vector<int>> us;
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         for(int k = j+1; k < n; k++){
        //             if(nums[i]+nums[j]+nums[k] == 0){
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 // ans.push_back({nums[i], nums[j], nums[k]});
        //                 us.insert(temp);
        //             }
        //         }
        //     }
        // }
        // for(auto val : st){
        //     ans.push_back(val);
        // }
        return ans;
    }
};