class Solution {
public:

    bool check10(int n)
    {
        int x = (int)(log10(n));
        while(x--)
        {
            int x = n%10;
            if(x!=0){return false;}
            n /= 10;
        }
        if(n==1){return true;}
        return false;
    }

    int makeIt(int n)
    {
        int x = (int)(log10(n))+1;
        int sum = 0;
        while(x--)
        {
            int p = n%10;
            sum += p*p;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int len = (int)(log10(n))+1;
        int stop = 0;
        while(check10(n)==false)
        {
            n = makeIt(n);
            stop++;
            if(stop>100){return false;}
        }
        return true;
    }
};