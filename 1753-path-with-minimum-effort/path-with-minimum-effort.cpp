#define vv(type) vector<vector<type>>
#define vvi vv(int)
#define vvb vv(bool)


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        // create a adj list[]
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        int n = mat.size();
        int m = mat[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // creates a min_heap pq;
        vvb explored(n, vector<bool>(m, false));
        vvi dis(n, vector<int>(m, INT_MAX));
        dis[0][0]=0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto pnode = pq.top();
            int pdis = pnode.first;
            int px = pnode.second.first;
            int py = pnode.second.second;
            explored[px][py]=true; // why can't a bettert path be there, because let say this was 2, and others were like 3, 4, ;
            // so that's why this 2 come first, and now 3 can't gie better than 2, it can give >=3 only, so once it is best among;
            // all nodes in pq, 
            pq.pop();
            for(int i = 0; i < 4; i++){
                int cx = px+dx[i];
                int cy = py+dy[i];
                if(cx<0||cx>=n||cy<0||cy>=m){continue;}
                if(!explored[cx][cy]){
                    int newt = max(abs(mat[px][py] - mat[cx][cy]), pdis);
                    if(newt < dis[cx][cy]){
                        dis[cx][cy]=newt;
                        // explored[cx][cy]=true; // why ek baarh me hi explored ??
                        pq.push({dis[cx][cy], {cx, cy}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};



/* METHOD - 1 RECURSION 
    // and no, we can't apply dp as i=1, j=1, may appear multiple times, but it's path will be different;

    #define vv(type) vector<vector<type>>
#define vvi vv(int)
#define vvb vv(bool)

class Solution {
public:

    void rec(int i, int j, vvi& mat, int& md, int pathmax, vvb& pathVis, int dx[], int dy[]){
        // cout << i << " " << j << '\n';
        int n = mat.size();
        int m = mat[0].size();
        if(i==n-1 && j==m-1){
            // cout << "inside md loop, this is pathmax -> " << pathmax << '\n';
            md = min(md, pathmax);
            return;
        }
        pathVis[i][j]=true;
        for(int index = 0; index < 4; index++){
            int cx = i+dx[index];
            int cy = j+dy[index];
            if(cx<0||cx>=n||cy<0||cy>=m){continue;}
            if(pathVis[cx][cy]){continue;}
            // cout << "parent -> " << i << " " << j << "  child -> " << cx << " " << cy << '\n';
            // cout << "this is before, pathmax -> " << pathmax;
            int pm = pathmax;
            pm=max(pathmax, abs(mat[i][j] - mat[cx][cy]));
            // pathmax = max(pathmax, abs(mat[i][j] - mat[cx][cy]));
            // cout << " after pathmax-> " << pathmax << '\n';
            rec(cx, cy, mat, md, pm, pathVis, dx, dy);
        }
        pathVis[i][j]=false;
    }

    int minimumEffortPath(vector<vector<int>>& mat) {
        int md = INT_MAX;
        int n = mat.size();
        int m = mat[0].size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        int pathmax=0;
        vvb pathVis(n, vector<bool>(m, false));
        rec(0, 0, mat, md, pathmax, pathVis, dx, dy);
        return md;
    }
};

*/