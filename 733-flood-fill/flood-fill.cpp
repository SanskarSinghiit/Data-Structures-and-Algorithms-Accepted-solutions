class Solution {
public:

    void bfs(vector<vector<int>>& image, int root, int color, int sr, int sc){
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({sr, sc});
        image[sr][sc] = color;
        int a[4] = {-1, 0, 1, 0};
        int b[4] = {0, 1, 0, -1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            for(int i = 0; i < 4; i++){
                int x1 = x + a[i];
                int y1 = y + b[i];
                if(x1>=n || y1>=m || x1<0 || y1 <0){
                    continue;
                } else if(image[x1][y1] != root){
                    continue;
                }
                image[x1][y1] = color;
                q.push({x1, y1});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int root = image[sr][sc];
        if(root == color){
            return image;
        }
        bfs(image, root, color, sr, sc);
        return image;
    }
};