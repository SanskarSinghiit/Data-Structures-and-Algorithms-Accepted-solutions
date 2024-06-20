class Solution {
public:

    bool isValid(int mid, vector<int>& position, int m){
        int n = position.size();
        //
        //  cout << "printing position => " << ' ';
        // for(auto val : position){
        //     cout << val << ' ';
        // } cout << '\n';
        // int prevPosition = 0;
        int balls = 0;
        int nextBall = 1;
        for(int i = 0; i <  n; i++){
            if(position[i]/*-prevPosition*/ >= nextBall){
                // cout << position[i] << ' ' << nextBall << '\n';
                balls++;
                nextBall = position[i] + mid;
                // prevPosition = position[i];
            }
        }
        cout << '\n';
        return balls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        // cout << "for mid = " << 26 << "isValid => " << '\n';
        // cout << isValid(26, position, m) << '\n';
        // return -1;
        int n = position.size();
        // range of answer = >  1 to 9999;
        int lo = 1;
        int hi = 999999999;
        int mid = lo + (hi-lo)/2;
        int ans = -1;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(isValid(mid, position, m)){
                // ans = (mid > ans) ? (mid) : (ans);
                ans = mid;
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        return ans;
    }
};