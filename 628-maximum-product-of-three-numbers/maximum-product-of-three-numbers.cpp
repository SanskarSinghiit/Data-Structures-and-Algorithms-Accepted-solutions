class Solution {
public:

    void countIncrement(int x, int& negcount, int& poscount, int& zerocount){
        if(x==0){
            zerocount++;
        } else if(x>0){
            poscount++;
        } else{
            negcount++;
        } return;
    }

    void reverse(vector<int>& vec){
        int n = vec.size();
        for(int i = 0; i < n/2; i++){
            swap(vec[i], vec[n-i-1]);
        }
    }

    int maximumProduct(vector<int>& nums)
    {
        int n = nums.size();
        int negcount = 0;
        int poscount = 0;  // 0 
        int zerocount = 0;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            countIncrement(x, negcount, poscount, zerocount);
        }
        vector<int> neg, pos;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(x<0){
                neg.push_back(x);
            } else if(x>0){
                pos.push_back(x);
            }
        }
        sort(nums.begin(), nums.end());
        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        // reverse(neg);
        int maxp = 1;
        // if(negcount==0){
        //     int doing = min(3, pos.size());
        //     if(doing<3){
        //         return 0;
        //     }
        //     while(doing--){
        //         maxp *= pos.back();
        //         pos.pop_back();
        //     }
        //     return maxp;
        // } else if(negcount==1){
        //     int doing = min(3, pos.size());
        //     int x = doing;
        //     while(doing--){
        //         maxp *= pos.back();
        //         pos.pop_back();
        //     }

        // }
        if(negcount<=1){  // neg ko lena hi nahi hai;;;
            for(int i = n-1; i >= n-3; i--){
                maxp *= nums[i];
            }
            return maxp;
        } else if(poscount==0){
            // reverse(neg);
            if(zerocount>0){
                return 0;
            } else{
                int doing = 3;
                while(doing--){
                    maxp *= neg.back();
                    neg.pop_back();
                }
                return maxp;
            }

        }
        else if(poscount<=2){  // and poscount >0;
            int doing = 2;
            reverse(neg);
            while(doing--){
                maxp *= neg.back();
                neg.pop_back();
            }
            maxp *= pos.back();
            return maxp;
        } else if(poscount>2){  // either choose all three pos, or choose 2neg and one pos, that's it; // and negcount >=2 hai yaha for sure;
            int propos = 1;
            // cout << "forpropos->" << '\n';
            for(int i = n-1; i>= n-3; i--){
                propos *= nums[i];
                // cout << propos << '\n';
            }
            int pro2neg1pos = 1;
            int doing = 2;
            reverse(neg);
            // cout << "forpro2neg1pos->" << '\n';
            while(doing--){
                pro2neg1pos *= neg.back();
                neg.pop_back();
                // cout << "inside while:" << pro2neg1pos << '\n';
            }
            pro2neg1pos *= pos.back();
            // cout << pro2neg1pos << '\n';
            maxp = max(propos, pro2neg1pos);
            return maxp;
        }
        return -1;  // never happens
    }
};