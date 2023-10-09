class Solution {
public:

    int first(vector<int>& nums, int target)
    {
        int first = -1;
        if(nums.size()==0)
        {
            return first;
        }
        int lo = 0;
        int hi = nums.size()-1;
        int mid = lo + (hi-lo)/2;
        while(lo<=hi)
        {
            if(nums[mid]==target)
            {
                first = mid;
                hi = mid - 1;
            }
            else if(nums[mid]>target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
            mid = lo + (hi-lo)/2;
        }
        return first;
    }

    int last(vector<int>& nums, int target)
    {
        int last = -1;
        if(nums.size()==0)
        {
            return last;
        }
        int lo = 0;
        int hi = nums.size()-1;
        int mid;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target)
            {
                last = mid;
                lo = mid + 1;
            }
            else if(nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans;
        ans.push_back(first(nums, target));    
        ans.push_back(last(nums, target));
        return ans;    
    }
};