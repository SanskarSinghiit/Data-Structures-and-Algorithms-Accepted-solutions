class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> hmp(26,0);
        int l = chars.size();
        for(int i = 0; i < l; i++)
        {
            hmp[chars[i]-'a']++;
        }

        int n = words.size();
        int cnt = 0;
        vector<int> dummy;
        for(int i = 0; i < n; i++)
        {
            // if not present then continue;
            dummy = hmp;
            bool cont = false;
            for(int j = 0; j < words[i].size(); j++)
            {
                char c = words[i][j];
                if(dummy[c-'a'] <= 0){cont=true; break;}
                else{dummy[c-'a']--;}
            }
            if(cont){continue;}
            // if present and then cnt++
            cnt += words[i].size();
            dummy.clear();
        }
        return cnt;
    }
};