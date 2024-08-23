class Solution {
public:

    int getLCM(int lcm, int x){
        return ((lcm*x)/__gcd(lcm, x));
    }

    string fractionAddition(string str) {
        int n = str.size();
        // vector<pair<int,int>> vec;
        // bool isNum = true;
        int sign=1; // means by default positive
        vector<int> num;
        vector<int> den;
        int x=0;
        for(int i = 0; i < str.size(); i++){
            if(str[i]>='0' && str[i]<='9'){
                x*=10;
                x+=(str[i]-'0');
            }
            if(str[i]=='/' && x!=0){
                num.push_back(x*sign); x=0; sign=1;
            } else if((str[i] == '+' || str[i]=='-') && (x!=0)){
                den.push_back(x); x=0;
            }
            if(str[i]=='-'){sign=-1;}
            if(str[i]=='+'){sign=1;}
        }
        den.push_back(x*sign);
        int lcm = 1;
        for(auto val : den){
            lcm = getLCM(lcm, val);
        }
        int numsum = 0;
        for(int i = 0; i < num.size(); i++){
            num[i] = (num[i]*lcm) / den[i];
            numsum+=num[i];
        }
        // num sum is numertor;
        // lcm is denominator;
    
        int hcf = __gcd(numsum, lcm);
        numsum/=hcf; lcm/=hcf;
        // hcf sign will tell if fraction is positive or negative, not the sign of numsum;
        string ans = "";
        if(hcf < 0){ans.push_back('-');}
        int hcfsgn = (hcf>0)?1:-1;
        string numstr=to_string(numsum); // numsum guaranteed to be positive;
        string denstr=to_string(lcm*hcfsgn);
        for(auto c : numstr){
            ans.push_back(c);
        } ans.push_back('/');
        for(auto c : denstr){
            ans.push_back(c);
        } return ans;
        // cout << "this is num -> "; for(auto val : num){cout << val << ' ';} cout << '\n';
        // cout << "this is den -> "; for(auto val : den){cout << val << ' ';} cout << '\n';
        // return "";
    }
};