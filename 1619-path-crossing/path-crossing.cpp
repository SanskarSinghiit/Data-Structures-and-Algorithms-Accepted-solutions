class Solution {
public:

    pair<int,int> nextPoint(pair<int,int>& prev, char c)
    {
        int x = prev.first;
        int y = prev.second;
        if(c=='N'){y = y + 1;}
        else if(c=='E'){x+=1;}
        else if(c=='S'){y-=1;}
        else if(c=='W'){x-=1;}
        return {x,y};
    }

    bool isPathCrossing(string path) 
    {
        int n = path.size();
        set<pair<int,int>> s;
        pair<int,int> prev = {0, 0};
        s.insert(prev);
        for(int i = 0; i < n; i++)
        {
            auto next = nextPoint(prev, path[i]);
            cout << next.first << " " << next.second << '\n';
            if(s.find(next)==s.end())
            {
                s.insert(next);
            }
            else
            {
                return true;
            }
            prev = next;
        }
        return false;
    }
};