class Solution {
public:

    void rec(vector<string>& arr, int i, set<char> st, int& maxx){
        if(i==arr.size()){
            return;
        }
        maxx = st.size() > maxx ? st.size() : maxx;
        rec(arr, i+1, st, maxx);
        maxx = st.size() > maxx ? st.size() : maxx;
        string str = arr[i];
        for(int i = 0; i < str.size(); i++){
            if(st.find(str[i])==st.end()){
                st.insert(str[i]);
            }
            else{
                return;
            }
        }
        maxx = st.size() > maxx ? st.size() : maxx;
        rec(arr, i+1, st, maxx);
        maxx = st.size() > maxx ? st.size() : maxx;
        return;
    }

    int maxLength(vector<string>& arr){
        int maxx = 0;
        int i = 0;
        set<char> st;
        rec(arr, i, st, maxx);
        return maxx;
    }
};