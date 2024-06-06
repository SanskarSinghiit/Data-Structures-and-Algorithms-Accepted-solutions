class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int x = groupSize;
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }
        while(mp.empty() == false){
            int val = (mp.begin())->first;
            cout <<  val << ' ';
            mp[val]--;
            if(mp[val] == 0){
                // cout << "got : " << val << " as zero" << " ";
                mp.erase(mp.find(val));
            }
            // cout << mp.find(val) << " ";
            // if(mp.find(val) == mp.end()){
            //     cout << "deleted " << val << ' ';
            // }
            // cout << "printing map => " << '\n';
            // for(auto val : mp){
            //     cout << val.first << ' ' << val.second << '\n';
            // }
            // cout << '\n';
            for(int i = 1; i < x; i++){
                int finds = val + i;
                // cout << finds << ' ';
                if(mp[finds] == 0){
                    return false;
                } else{
                    mp[finds]--;
                    if(mp[finds] == 0){
                        mp.erase(mp.find(finds));
                    }
                }
            }
            cout << '\n';
        }
        return true;    
    }
};