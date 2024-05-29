class Solution {
public:

void add1(string &s)
{
    int n = s.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (carry == 0)
        {
            break;
        }
        else if (s[i] == '0' && carry == 1)
        {
            s[i] = '1';
            carry = 0;
        }
        else if (s[i] == '1' && carry == 1)
        {
            s[i] = '0';
            carry = 1;
        }
        if(i==0 && carry == 1){
            string str = "";
            str.push_back('1');
            str += s;
            s = str;
            str.clear();
        }
    }
}

int numSteps(string s)
{
    int n = s.size();
    int count = 0;
    while (s != "1")
    {
        count++;
        // cout << "hi";
        if (s.back() == '0')
        {
            s.pop_back();
        }
        else
        {
            add1(s);
        }
        // cout << "hi";
        // cout << s << '\n';
    }
    return count;
}
};