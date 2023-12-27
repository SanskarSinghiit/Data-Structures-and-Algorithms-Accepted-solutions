class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = neededTime.size();
        int maxTime = neededTime[0];
        int maxIndex = 0;
        map<int, char> mp;
        for(int i = 1; i < n; i++)
        {
            if(colors[i]==colors[i-1]){
                int x = neededTime[i];
                if(x>maxTime){maxIndex=i; maxTime=x;}
                if(i==n-1)
                {
                    mp.insert({maxIndex, colors[i]});
                }
            }
            else{
                mp.insert({maxIndex, colors[i-1]});
                maxTime = neededTime[i];
                maxIndex = i;
                if(i==n-1){
                    mp.insert({n-1, colors[n-1]});
                }
            }
        }
        int cnt = 0;
        auto it = mp.begin();
        // int j = 0;
        for(int i = 0; i < n; i++){
            if(i==(*it).first)
            {
                // j++;
                it = next(it, 1);
                continue;
            }
            else
            {
                cnt+=neededTime[i];
            }
        }
        return cnt;
    }
};