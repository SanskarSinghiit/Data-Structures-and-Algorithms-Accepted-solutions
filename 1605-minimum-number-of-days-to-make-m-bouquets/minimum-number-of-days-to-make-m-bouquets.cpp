typedef long long ll;
class Solution {
public:

    // void print(priority_queue<int>& pq){
    //     cout << "pq => ";
    //     while(!pq.empty()){
    //         cout << pq.top() << ' ';
    //         pq.pop();
    //     }
    //     cout << '\n';
    // }

    // void print(vector<int>& vec){
    //     for(auto val : vec){
    //         cout << val << ' ';
    //     } cout << '\n';
    // }

    // vector<int> fillWith(queue<int> q){
    //     vector<int> temp;
    //     while(!q.empty()){
    //         temp.push_back(q.front());
    //         q.pop();
    //     }
    //     return temp;
    // }

    bool check(int day, vector<int>& bloomDay, int m, int k, int n){
        int count = 0;
        // bool print = false;
        // if(day==8){
        //     print = true;
        // }
        int bouquet = 0;
        for(int i = 0; i < n; i++){
            // if(print){
            //     cout << " for i => " << i << " ";
            // }
            if(bloomDay[i] <= day){
                // if(print){
                //     cout << "blooms" << " ";
                // }
                count++;
            } else{
                count = 0;
            }
            // if(print){
            //     cout << "count => " << count << "  ";
            // }
            if(count == k){
                bouquet++;
                count = 0;
            }
            // if(print){
            //     cout << " bouquet => " << bouquet << "  count => " << count << '\n';
            // }
        }
        // if(print){
        //     cout << "and the value of m => " << m << '\n';
        //     cout << "and the value of bouquet => " << bouquet << '\n';
        // }
        return (bouquet >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m*1LL*k;
        if(val > n){
            return -1;
        }
        int lo = 0;
        int hi = 1e9;
        int mid  = lo + (hi-lo)/2;
        int possible = -1;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(check(mid, bloomDay, m, k, n)){
                possible = mid;
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        return possible;
        // int n = bloomDay.size();
        // if(m*k > n){
        //     return -1;
        // }
        // if(n==1){
        //     return bloomDay[0];
        // }
        // vector<int> maxOfSubarray;  // n-k+1 subarrays each of size == k, 
        // // and find the max element and store in this
        // // int max = -1;
        // // int secMax = -1;
        // queue<int> q;

        // for(int i = 0; i < n; i++){
        //     int x = bloomDay[i];
        //     q.push(x);
        //     // if(x > max){
        //     //     secMax = max;
        //     //     max = x;
        //     // } else if(x > secMax){
        //     //     secMax = x;
        //     // }
        //     if(i >= k-1){
        //         cout << "i=>" << i << "  " << "vector => ";
        //         vector<int> temp = fillWith(q);
        //         print(temp);
        //         maxOfSubarray.push_back(*max_element(temp.begin(), temp.end()));
        //         // priority_queue<int> temp = pq;
        //         print(temp);
        //         q.pop();
        //     }
        // }
        // // sort(maxOfSubarray.begin(), maxOfSubarray.end());
        // int maxi = -1;
        // for(int i = 0; i < m; i++){
        //     if(maxOfSubarray[i] > maxi){
        //         maxi = maxOfSubarray[i];
        //     }
        // }
        // return maxi;
    }
};