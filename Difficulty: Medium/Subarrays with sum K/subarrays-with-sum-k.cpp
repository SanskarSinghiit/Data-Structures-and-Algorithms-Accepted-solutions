//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }
        map<int, int> mp;
        // for(int i = 0; i < n; i++){
        //     mp[prefix[i]]++;
        // }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(prefix[i]==k){count++;}
            auto it = mp.find(prefix[i]-k);
            if(it!=mp.end()){
                // int index = it->second;
                count += it->second;
            }
            mp[prefix[i]]++;
            // cout << " i-> " << i << "  count -> " << count << '\n';
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends