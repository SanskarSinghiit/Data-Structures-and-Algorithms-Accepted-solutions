// #define vi vector<int>

class Solution {
public:

    static bool custom(vector<int>& a, vector<int>& b){
        // if(a[1]==b[1]){return true;}
        return a[1]<b[1];
    }

    bool good(vector<int>& a, vector<int>& b){
        if(b[0]<a[1] && b[1]>a[0]){return false;}
        return true;
    }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), custom);
        int count = 1;
        vector<int> prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(good(prev, intervals[i])){ prev=intervals[i]; count++;}
        }
        //cout << "this is count - > " << count << '\n';
        return intervals.size()-count;
    }
};