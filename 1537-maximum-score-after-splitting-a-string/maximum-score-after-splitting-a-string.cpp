class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        // vector<pair<int,int>> vec(n);
        // if(s[0].first=='0'){vec[0].first=1; vec[0].second=0;}
        // else{vec[0].first=0; vec[0].second=1;}
        // for(int i = 1; i < n; i++){
        //     if(s[i]=='0'){
        //         vec[i].first = vec[i-1].first + 1;
        //         vec[i].second = vec[i-1].second;
        //     } else{
        //         vec[i].second = vec[i-1].second+1;
        //         vec[i].first = vec[i-1].first;
        //     }
        // }
        // ith index means i to n-1 all in rhs;
        int zeros = 0;
        int ones = 0;
        int total_ones = 0;
        for(int i = 0; i < n; i++){
            if(s[i]=='1'){total_ones++;}
        }
        int max_score = -1;
        for(int i = 0; i < n; i++){
            int x = zeros;
            int y = total_ones - ones;
            if(x+y>max_score && i>0){max_score=x+y;}
            if(s[i]=='0'){zeros++;}
            else{ones++;}
        }
        // int x = zeros; int y = total_ones - ones;
        // if(x+y>max_score){max_score=x+y;}
        return max_score;
    }
};