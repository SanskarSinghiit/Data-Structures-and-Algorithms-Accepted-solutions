class Solution {
public:
    int lengthOfLongestSubstring(string str)
    {
        int n = str.size();
        int j = 0;
        set<char> st;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(j==n){
                break;
            }
            char c = str[j];
            // cout << "i->" << i << " st->";
            // for(auto val : st){
            //     cout << val << ' ';
            // } cout << '\n';
            while(st.find(str[j])==st.end()){
                st.insert(str[j]);
                maxi = j-i+1 > maxi ? j-i+1 : maxi;
                // cout << "maxi->" << maxi << '\n';
                j++;
                if(j==n){
                    break;
                }
                // c = str[j];
            }
            if(j==n){break;}
            if(st.find(str[j])!=st.end()) {
                st.erase(st.find(str[i]));
            }
            // cout << "i->" << i << " st->";
            // for(auto val : st){
            //     cout << val << ' ';
            // } cout << '\n' << '\n';
        }
        return maxi;
    // longest substring so no child concept; OK
    //     set<char> s;
    //     int n = str.size();
    //     int longest = 0;
    //     int i = 0; int j = 0;
    //     while(j<n)  // ratt lo ki j < n ;
    //     {
    //         char c = str[j];
    //         cout << "i-> "<<i<< " c->" << c <<'\n'; 
    //         if(s.find(c)==s.end())
    //         {
    //             s.insert(c);
    //             longest = (j-i+1 > longest) ? (j-i+1) : (longest);
    //             j++;
    //         }
    //         else
    //         {
    //             while(s.find(c) != s.end())
    //             {
    //                 cout << "else : c->" << c << " i->" << i << ' ';
    //                 cout << "hello ";
    //                 auto it = s.begin();
    //                 cout << "it->" << *it << '\n';
    //                 s.erase(it);
    //                 i++;
    //             }
    //             s.insert(c);
    //             longest = (j-i+1 > longest) ? (j-i+1) : (longest);
    //             j++;
    //         }
    //     }
    //     return longest;
    }
};