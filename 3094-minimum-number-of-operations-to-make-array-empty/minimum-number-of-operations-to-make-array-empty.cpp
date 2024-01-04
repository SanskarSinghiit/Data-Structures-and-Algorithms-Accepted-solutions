class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(mp.find(x)==mp.end()){
                mp.insert({x, 1});
            }
            else{
                mp[x]++;
            }
        }
        for(auto val : mp){
            if(val.second==1){return -1;}
        }
        int cnt = 0;
        for(auto& val : mp){
            int& y = val.second;
            while(y > 4){
                y -= 3;
                cnt++;
            }
            if(y==2){
                y-=2;
                cnt++;
            }
            else if(y==3){
                y-=3;
                cnt++;
            }
            else if(y==4){
                y -= 4;
                cnt += 2;
            }
        }
        return cnt;
    }
};