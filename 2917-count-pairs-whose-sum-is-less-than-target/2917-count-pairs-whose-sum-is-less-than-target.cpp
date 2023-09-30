class Solution {
public:
    int countPairs(vector<int>& nums, int target)
    {
        // int cnt = 0;
        // int n = nums.size();
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = i+1; j < n; j++)
        //     {
        //         if(nums[i]+nums[j] < target)
        //         {
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        int n = nums.size();
        int st = 0;
        int end= n-1;
        int cnt = 0;
        int sum = 0;
        sort(nums.begin(), nums.end());
        while(st<end)
        {
            sum = nums[st] + nums[end];
            if(sum>=target)
            {
                end--;
                continue;
            }
            else
            {
                cnt += (end - st);
                cout << st << " " << end << '\n';
                st++;
            }
        }
        return cnt;
    }
};