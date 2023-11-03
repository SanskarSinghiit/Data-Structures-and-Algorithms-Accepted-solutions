class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> stack;
        // string push = "Push", pop = "Pop";
        int m = target.size();// m is the size of the target int array;
        // n is the size of the stream of integers available for use;
        int i = 0; // iterates target
        int j = 1; // iterates stream of integers(represents basically);
        while(i < m)
        {
            while(j<target[i])
            {
                j++;
                stack.push_back("Push");
                stack.push_back("Pop");
            }
            stack.push_back("Push");
            i++; j++;
        }
        return stack;
    }
};