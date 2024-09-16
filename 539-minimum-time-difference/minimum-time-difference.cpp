class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        // O(N*N) solution;
        vector<int> v;
        for(int i = 0; i < timePoints.size(); i++){
            string str = timePoints[i];
            int hour = 0;
            hour += (str[0]-'0');
            hour *= 10;
            hour += (str[1]-'0');
            int minutes = 0;
            minutes += (str[3]-'0');
            minutes*=10;
            minutes+=(str[4]-'0');
            // cout << "this is hours -> " << hour << "  this is minutes -> " << minutes << '\n';
            minutes += hour*60;
            v.push_back(minutes);
        }
        // cout << "this is v -> "; for(auto val : v){cout << val << ' ';} cout << '\n';
        int minv = INT_MAX;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                int x = v[i];
                int y = v[j];
                // int val = min(abs(x-y), x+y);
                int a = max(x, y);
                int b = min(x, y);
                // cout << "a -> " << a << "  b -> " << b << '\n';
                int val = min(abs(a-b), 1440-a+b);
                if(val<minv){minv=val;}
            }
        }
        return minv;
    }
};