class Solution {
public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int xc = 0;
        int yc = 0;
        int dir = 0;
        int maxdis = -1;
        set<pair<int,int>> st;
        for(auto val : obstacles){
            st.insert({val[0], val[1]});
        }
        for(int i = 0; i < n; i++){
            if(commands[i] == -1){
                dir = (dir+1)%4;
            } else if(commands[i] == -2){
                dir = (dir-1 + 4)%4;
            } else{
                int xb = xc; int yb = yc;
                for(int p = 1; p <= commands[i]; p++){
                    int x = xc; int y = yc;
                    if(dir==0){
                        y=yb+p;
                    } else if(dir==1){
                        x=xb+p;
                    } else if(dir==2){
                        y=yb-p;
                    } else if(dir==3){
                        x=xb-p;
                    }
                    if(st.find({x, y}) != st.end()){
                        break;
                    } else{
                        xc = x; yc = y;
                    }
                } 
            }
            int distance = xc*xc+yc*yc;
            if(distance > maxdis){maxdis=distance;}
        }
        // don't tell the final point, tell me the furthest point
        return maxdis;
    }
};