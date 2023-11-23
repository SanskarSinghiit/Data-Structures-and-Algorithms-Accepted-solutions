class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> answer;
        int n = nums.size();
        int m = l.size();
        for(int i = 0; i < m; i++)
        {
            int left = l[i]; int right = r[i];
            vector<int> sample;
            for(int i = left; i <= right; i++)
            {
                sample.push_back(nums[i]);
            }
            if(sample.size()==1){answer.push_back(true); continue;}
            sort(sample.begin(), sample.end());
            int diff = sample[1]-sample[0];
            bool foundAFlaw = false;
            for(int i = 1; i < sample.size(); i++)
            {
                int d = sample[i]-sample[i-1];
                if(d!=diff){foundAFlaw=true; break;}
            }
            answer.push_back(!foundAFlaw);
        }
        return answer;
    }
};