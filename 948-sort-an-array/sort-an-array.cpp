class Solution {
public:

    vector<int> rec(vector<int>& nums, int s, int e, int& count){
        // cout << "hi" << " ";
        if(e-s == 0){
            // cout << "s -> " << s << " e -> " << e << '\n';
            // cout << "merge => " << "  " << nums[s] << '\n';
            return {nums[s]};
        }
        int mid = s+(e-s)/2;
        vector<int> left = rec(nums, s, mid, count);
        vector<int> right= rec(nums, mid+1, e, count);
        // cout << "s -> " << s << " e -> " << e << '\n';
        // cout << "left => " << "  ";
        // for(auto val : left){
        //     cout << val << ' ';
        // } cout << "   ";
        // cout << "right => " << "  ";
        // for(auto val : right){
        //     cout << val << ' ';
        // } cout << "   ";
        int i = 0; int ls = left.size();
        int j = 0; int rs = right.size();
        vector<int> merge;
        while(i < ls || j < rs){
            if(i==ls){
                count++;
                merge.push_back(right[j++]);
            } else if(j==rs){
                count++;
                merge.push_back(left[i++]);
            } else{
                if(left[i] <= right[j]){
                    merge.push_back(left[i++]);
                } else{
                    merge.push_back(right[j++]);
                }
                count++;
            }
        }
        // cout << "merge => " << "  ";
        // for(auto val : merge){
        //     cout << val << ' ';
        // } cout << '\n';
        return merge;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s+(e-s)/2;
        int count = 0;
        vector<int> ans = rec(nums, 0, n-1, count);
        // cout << count << '\n';
        return ans;
    }
};