//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int j = n-1;
        int count = 0;
        // cout << "arr -> ";
        // for(auto val : arr){
        //     cout << val << ' ';
        // } cout << '\n';
        for(int i = 0; i < n; i++){
            if(j<=i){break;}
            while(arr[i]+arr[j]>=target && j>i){j--;}
            // cout << " i-> " << i << "  j-> " << j << '\n';
            count += j-i;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends