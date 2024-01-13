class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;
        for(int i = 0; i < s.size(); i++){
            if(ms.find(s[i])==ms.end()){
                ms.insert({s[i], 1});
            }
            else{
                ms[s[i]]++;
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(mt.find(t[i])==mt.end()){
                mt.insert({t[i], 1});
            }
            else{
                mt[t[i]]++;
            }
        }
        int count = 0;
        for(auto val : ms){
            char c = val.first;
            if(mt.find(c)==mt.end()){
                count += val.second;
            }
            else{
                count += max(0, (val.second - mt.find(c)->second));
            }
        }
        return count;
    }
};