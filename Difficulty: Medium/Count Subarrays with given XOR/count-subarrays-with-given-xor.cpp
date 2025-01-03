//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define lg long

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i = 1; i < n; i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        lg count = 0;
        map<int,int> mp;
        int xorr = 0;
        for(int i = 0; i < n; i++){
            xorr ^= arr[i];
            if(xorr==k){count++;}
            auto it = mp.find(xorr^k);
            if(it!=mp.end()){
                count+=it->second;
            }
            mp[xorr]++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends