class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        vector<int> children;
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(g.size()>0){
            children.push_back(g.back());
            g.pop_back();
        }
        /*cout << "prints children -> ";
        for(auto val : children){
            cout << val << ' ';
        } cout << '\n';*/
        int maxc = 0;
        for(int i = 0; i < m; i++){
            if(children.size()==0){break;}
            // cout << "this is children.back() -> " << children.back() << '\n';
            // cout << "this is s[i] -> " << s[i] << '\n';
            if(children.back() > s[i]){
                continue;
            } else{
                maxc++;
                children.pop_back();
            }
        }
        return maxc;
    }
};