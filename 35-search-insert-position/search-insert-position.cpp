class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        int mid = lo + (hi-lo)/2;
        int index = n;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid] == target){
                return mid;
            } else if(arr[mid] < target){
                lo = mid+1;
                // cout << "in 2nd case : " << '\n';
            } else if(arr[mid] > target){
                // cout << "in 3rd case : " << "  ";
                // cout << "target => " << target << " arr[mid] => " << arr[mid] << '\n';
                index = mid;
                hi = mid-1;
                // cout << "so lo => " << lo << " hi => " << hi << " and index => " << index << '\n';
            }
            // cout << '\n';
        }
        return index;
    }
};