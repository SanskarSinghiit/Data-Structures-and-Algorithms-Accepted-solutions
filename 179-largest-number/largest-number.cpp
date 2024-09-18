class Solution {
public:

    static bool custom(string a, string b){
        if(a+b > b+a){
            return true;
        }
        return false;
        // int m = a.size();
        // int n = b.size();
        // // cout << "this is a -> " << a << "  this is b -> " << b << '\n';
        // if(m==0){
        //     return false;
        // } else if(n==0){
        //     return true;
        // } 
        // // cout << "this is m -> " << m << "  this is n -> " << n << '\n';
        // // cout << "this is (int)pow(10, m-1) -> " << (int)pow(10, m-1) << "  (int)pow(10, n-1) -> " << (int)pow(10, n-1) << '\n';
        // // cout << "this is a%((int)pow(10, m-1)) -> " << a%((int)pow(10, m-1)) << "  this is b%((int)pow(10, n-1)) -> " << b%((int)pow(10, n-1)) << '\n';
        // // if(a%((int)pow(10, m-1))!=b%((int)pow(10, n-1))){
        // //     cout << "inside A" << '\n';
        // //     return a%((int)pow(10, m-1))>b%((int)pow(10, n-1));
        // // }
        // // if(a[0]!=b[0]){

        // // }
        // // int m = a.size();
        // // int n = b.size();
        // int i = 0;
        // int j = 0;
        // // int pow1 = int(pow(10, m-1));
        // // int pow2 = int(pow(10, n-1));
        // while(i<m&&j<n){
        //     if(a[i]!=b[i]){
        //         return a[i]>b[i];
        //     }
        //     i++; j++;
        // }
        
        // // while(pow1 >= 1 && pow2>=1){
        // //     cout << "inside B" << '\n';
        // //     if(a%pow1==b%pow2){pow1/=10; pow2/=10; continue;}
        // //     return a%pow1>b%pow2;
        // // }
        // // cout << "inside C" << '\n';
        // string z = m>n ? a:b;
        // string t = m<=n?a:b;
        // int sz = max(m, n);
        // int ind = m>n?i:j;
        // // cout << "z-> " << z << " t-> " << t << " a-> " << a << " b-> " << b << '\n';
        // // cout << z[ind] << " compares with " << t.back() << '\n';
        // while(ind<sz){
        //     // cout << "here" << '\n';
        //     char c = z[ind++];
        //     if(c>t.back()){
        //         // cout << "true" << '\n';
        //         return z==a;
        //     } else if(c<t.back()){
        //         return z!=a;
        //     }
        // }
        // return m>n;
    }

    string largestNumber(vector<int>& nums) {
        // str[0] highest will be placed first;
        // if two numbers have same str[0]; str[1] highest will be placed first,
        // custom sort;
        vector<string> vec;
        for(auto x : nums){
            vec.push_back(to_string(x));
        }
        sort(vec.begin(), vec.end(), custom);
        string str = "";
        for(auto x : vec){
            // string temp = to_string(x);
            // if(x=="0"){continue;}
            for(auto c : x){
                str.push_back(c);
            }
        }
        // if(str==""){return "0";}
        while(str[0]=='0'&&str.back()=='0'&&str.size()>1){
            str.pop_back();
        }
        return str;
    }
};