class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        int m = piles.size();
        // m is 3n
        int n = m/3;
        sort(piles.begin(), piles.end());
        int count = 0;
        deque<int> q;
        for(int i = 0; i < m; i++)
        {
            q.push_back(piles[i]);
        }
        // deque<int> q1 = q;
        // while(!q1.empty())
        // {
        //     cout << q1.front() << ' ';
        //     q1.pop_front();
        // }
        for(int i = 0; i < n; i++)
        {
            q.pop_back();
            count += q.back();
            q.pop_back();
            q.pop_front();
        }
        return count;
    }
};