//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        int count=1;
        while(i < n || j < m){
            if(i==n){
                // if(count==k){
                //     return b[j];
                // } count++;
                ans.push_back(b[j++]);
                // cout << b[j++] << ' ';
                continue;
            } else if(j==m){
                // if(count==k){
                //     return a[i];
                // } count++;
                ans.push_back(a[i++]);
                // cout << a[i++] << ' ';
                continue;
            }
            if(a[i]<=b[j]){
                // cout << a[i] << ' ';
                ans.push_back(a[i]);
                // if(count==k){return a[i];}
                i++;
            } else{
                ans.push_back(b[j]);
                // if(count==k){return b[j];}
                // cout << b[j] << ' ';
                j++;
            } //count++;
        }
        return ans[k-1];
        // return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends