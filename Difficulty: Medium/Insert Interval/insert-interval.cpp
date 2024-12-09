//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool overlap(vector<int>&x, vector<int>&y){
        int a = x[0]; int b = x[1];
        int c = y[0]; int d = y[1];
        if(b>=c &&a<=d){return true;}
        return false;
    }
  
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(overlap(ans.back(), intervals[i])){
                int a = ans.back()[0]; int b = ans.back()[1];
                int c = intervals[i][0]; int d = intervals[i][1];
                ans.pop_back();
                ans.push_back({min(a,c),max(b,d)});
            } else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends