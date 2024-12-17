//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// BINARY SEARCH ON ANSWERS;
class Solution {
  public:

    bool isPossible(int ans, vector<int>& stalls, int k){
        int prev = stalls[0];
        int count = 1;
        int n = stalls.size();
        for(int i = 1; i < n; i++){
            if(count>=k){return true;}
            int curr = stalls[i];
            if(curr-prev >= ans){count++; prev=curr;}
        }
        return count>=k;
    }
    // void print(vector<int>& stalls){
    //     for(auto val : stalls){
    //         cout << val << ' ';
    //     } cout << '\n';
    // }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        int lo = 1;
        int hi = *max_element(stalls.begin(), stalls.end());
        int mid = lo + (hi-lo)/2;
        int maxi = -1;
        sort(stalls.begin(), stalls.end());
        // cout << "printing stalls -> " << '\n';
        // print(stalls);
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(isPossible(mid,stalls,k)){
                // cout << "possible mid = " << mid << "  ";
                maxi = max(maxi, mid);
                lo = mid+1;
            } else{
                hi=mid-1;
            }
        }
        if(maxi==-1){return 0;}
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends