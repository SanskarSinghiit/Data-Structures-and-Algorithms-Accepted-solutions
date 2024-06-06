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
                mp.erase(mp.find(val));
            }
            for(int i = 1; i < x; i++){
                int finds = val + i;
                if(mp[finds] == 0){
                    return false;
                } else{
                    mp[finds]--;
                    if(mp[finds] == 0){
                        mp.erase(mp.find(finds));
                    }
                }
            }
        }
        return true;    
    }
};