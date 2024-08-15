class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int x = 0;
        int y = 0;
        int z = 0;
        for(auto val : bills){
            if(val==5){ x++;
                continue;
            } else if(val==10){ y++;
                if(x==0){return false;}
                else{x--;}
            } else{ z++;
                if(y==0){
                    if(x<3){return false;}
                    else{x-=3;}
                } else{
                    y--;
                    if(x==0){return false;}
                    else{x--;}
                }
            }
        }
        return true;
    }
};