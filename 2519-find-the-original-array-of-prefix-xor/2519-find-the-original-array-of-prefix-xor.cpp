class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        int n = pref.size();
        vector<int> arr(n);
        arr[0] = pref[0];
        int till_xor = arr[0];
        for(int i = 1; i < n; i++)
        {
            arr[i] = (till_xor) ^ pref[i];
            till_xor ^= arr[i];
        }
        return arr;
    }
};