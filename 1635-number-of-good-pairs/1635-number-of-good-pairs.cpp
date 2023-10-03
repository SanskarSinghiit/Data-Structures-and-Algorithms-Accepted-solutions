class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        unordered_map<int, int> um;
        sort(nums.begin(), nums.end());

        int cnt = 1;
        int n = nums.size();
        um.insert({nums[0], 1});

        for(int i = 1; i < n; i++)
        {
            if(nums[i]!=nums[i-1])
            {
                um.insert({nums[i], 1});
            }
            else
            {
                um[nums[i]]++;
            }
        }
        int ans = 0;
        for(auto value : um)
        {
            int x = value.second;
            if(x>1){ans += (x)*(x-1)/2;}
        }
        return ans;
    }
};