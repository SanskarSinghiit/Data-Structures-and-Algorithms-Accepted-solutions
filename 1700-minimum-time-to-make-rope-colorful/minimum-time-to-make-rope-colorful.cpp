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
            if(colors[i]==colors[i-1])
            {
                int x = neededTime[i];
                if(x>maxTime){maxIndex=i; maxTime=x;}
                if(i==n-1)
                {
                    mp.insert({maxIndex, colors[i]});
                }
            }
            else
            {
                mp.insert({maxIndex, colors[i-1]});
                maxTime = neededTime[i];
                maxIndex = i;
                if(i==n-1){
                    mp.insert({n-1, colors[n-1]});
                }
            }
        }
        // printing the map ;
        // for(auto val : mp)
        // {
        //     cout << val.first << " " << val.second << '\n';
        // }
        int cnt = 0;
    //     int j = 0;
    // //  it;
    //     int mapIndex;
    //     int mapColor;
    //     for(int i = 0; i < n; i++)
    //     {
    //         auto it = next(mp.begin(), j);
    //         mapIndex = (*it).first;
    //         mapColor = (*it).second;
    //         if(i==mapIndex)
    //         {
    //             j++;
    //             continue;
    //         }
    //         else
    //         {
    //             cnt+=neededTime[i];
    //         }
    //     }
        // return 0;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(i)==mp.end()){cnt+=neededTime[i];}
        }
        return cnt;

    }
};