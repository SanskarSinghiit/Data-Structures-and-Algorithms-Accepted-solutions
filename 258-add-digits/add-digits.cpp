class Solution {
public:
    int addDigits(int num)
    {
        string str = to_string(num);
        while(str.size()>1)
        {
            num = 0;
            for(int i = 0; i < str.size(); i++){num+=(str[i]-'0');}
            str = to_string(num);
        }
        return str[0]-'0';
    }
};