class Solution {
public:

    void fill(vector<string>& vec, string& str){
        string temp = "";
        int n = str.size();
        for(auto val : str){
            if(val==' '){
                if(temp.size()>0){
                    vec.push_back(temp);
                    temp.clear();
                } 
            } else{
                temp.push_back(val);
            }
        }
        if(temp.size()>0){
            vec.push_back(temp);
            temp.clear();
        }
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {

        // int i = 0; int j = 0;
        int n = sentence1.size(); int m = sentence2.size();
        vector<string> vs1, vs2;
        string s1 = n > m ? sentence1 : sentence2;
        string s2 = n > m ? sentence2 : sentence1;
        // cout << "s1-> " << s1 << '\n';
        // cout << "s2-> " << s2 << '\n';
        fill(vs1, s1);
        fill(vs2, s2);
        n=vs1.size();
        m=vs2.size();
        // cout << "n -> " << n << " m-> " << m << '\n';
        int l1=0; int r1=n-1;
        int l2=0; int r2=m-1;
        if(m==1){
            if(vs2[0]==vs1[0]||vs2[0]==vs1[n-1]){return true;}
            return false;
        }
        while(l2<m&&l1<n){
            if(vs1[l1]==vs2[l2]){l1++; l2++;}
            else{break;}
        } // cout << "l1 -> " << l1 << " " << " l2 -> " << l2 << '\n';
        while(r2>=0 && r1>=0){
            if(vs1[r1]==vs2[r2]){r1--; r2--;}
            else{break;}
        } // cout << "r1 -> " << r1 << " " << " r2 -> " << r2 << '\n';
        if(r2-l2<0){return true;}
        return false;

        // int conflict = 0;
        // cout << "vs1 -> " << '\n';
        // n = vs1.size(); m = vs2.size();
        // set<string> st1, st2;
        // for(auto val : vs1){
        //     st1.insert(val);
        // }
        // for(auto val : vs2){
        //     st2.insert(val);
        // }
        // for(auto val : st2){
        //     if(st1.find(val)==st1.end()){return false;}
        // }
        // // for(auto val : vs1){cout<<val<<' ';} cout << '\n';
        // // for(auto val : vs2){cout<<val<<' ';} cout << '\n';
        // while(i < n && j < m){
        //     if(vs1[i]==vs2[j]){i++; j++; continue;}
        //     else{
        //         conflict++;
        //         while(i<n && vs1[i]!=vs2[j]){i++;}
        //     }
        // }
        // if(j==m && i < n){conflict++;}
        // if(conflict>=2){return false;}
        // // if(conflict==1)
        // return true;
    }
};