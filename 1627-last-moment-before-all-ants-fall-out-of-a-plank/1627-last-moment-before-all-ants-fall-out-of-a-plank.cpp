class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right)
    {
        int x = (left.size()!=0) ? *max_element(left.begin(), left.end()) : -1;
        int y = (right.size()!=0) ? *min_element(right.begin(),right.end()) : -1;
        if(x==-1 && y==-1){return 0;}
        int a = x-0;
        int b = n-y;
        if(x==-1){return b;}
        if(y==-1){return a;}
        int c = max(a, b);
        return c;   
    }
};