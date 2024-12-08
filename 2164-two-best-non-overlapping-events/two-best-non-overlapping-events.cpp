// class Solution {
// public:

//     bool overlap(vector<int>& x, vector<int>& y){
//         int a = x[0]; int b = x[1];
//         int c = y[0]; int d = y[1];
//         if(a<=d && b>=c){return true;}
//         return false;
//     }

//     int maxTwoEvents(vector<vector<int>>& events) {
//         int n = events.size();
//         sort(events.begin(), events.end());
//         int maxi = INT_MIN;
//         // cout << "printing events matrix -> " << '\n';
//         // for(auto v : events){
//         //     for(auto val : v){
//         //         cout << val << ' ';
//         //     } cout << '\n';
//         // }
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 if(overlap(events[i], events[j])){
//                     // cout << i << " and " << j << " overlap each other " << '\n';
//                     continue;
//                 } // cout << i << " and " << j << " don't overlap each other " << '\n';
//                 int p = events[i][2];
//                 int q = events[j][2];
//                 maxi = max(maxi, p+q);
//             }
//             maxi = max(maxi, events[i][2]);
//         }
//         return maxi;
//     }
// };



class Solution {
    public:
struct custom {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};


    int maxTwoEvents(vector<vector<int>>& events){
        int prev_max = -1;
        int ans = -1;
        int n = events.size();
        sort(events.begin(), events.end());
        // cout << "printing events matrix -> " << '\n';
        // for(auto v : events){
        //     for(auto val : v){
        //         cout << val << ' ';
        //     } cout << '\n';
        // }
        priority_queue<vector<int>, vector<vector<int>>, custom> pq; 
        // this stores all previous intervals that are currently overlapping to the current interval;
        for(int i = 0; i < n; i++){
            vector<int> current = events[i];
            // cout << "this is current -> " << current[0] << ' ' << current[1] << ' ' << current[2] << '\n';
            // first remove from pq all those events which are not overlappinf with the current event;
            while(pq.size()>0){
                vector<int> temp = pq.top();
                if(temp[1]<current[0]){
                    prev_max = max(prev_max, temp[2]);
                    // cout << "removing this -> " << temp[0] << ' ' << temp[1] << ' ' << temp[2] << '\n';
                    pq.pop();
                } else{
                    break;
                }
            } // cout << '\n';

            // first check with prev_max and current to get the max pair sum w.r.t. current;
            if(prev_max!=-1){
                ans = max(ans, prev_max+current[2]);
            }
            // now all done just check for single also, 
            ans = max(ans, current[2]);
            pq.push(current);
            // nowjust remove from the pq those elements which will not overlap with next ones
        }
        return ans;
    }
};