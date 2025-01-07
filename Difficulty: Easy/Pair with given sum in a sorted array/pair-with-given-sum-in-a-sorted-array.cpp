//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size();
        // int lo = 0;
        // int hi = n-1;
        // int count = 0;
        // while(lo<=hi){
        //     int sum = arr[lo]+arr[hi];
        //     if(sum < target){
        //         lo++;
        //     } else if(sum > target){
        //         hi--;
        //     } else{
        //         count++;
        //         lo++; hi--;
        //     }
        // }
        // return count;
        int count = 0;
        map<int,int> mp;
        // for(auto val : arr){
        //     mp[val]++;
        // }
        for(int i = 0; i < n; i++){
            int x = target - arr[i];
            auto it = mp.find(x);
            if(it!=mp.end()){count += it->second;}
            mp[arr[i]]++;
        }
        // for(auto ix = mp.begin(); ix != mp.end(); ix++){
        //     int x = target - ix->first;
        //     auto it = mp.find(x);
        //     if(it==mp.end()){continue;}
        //     cout << "this is arr[i] -> " << ix->first << "  this is x -> " << x << '\n';
        //     count += it->second;
        // }
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends