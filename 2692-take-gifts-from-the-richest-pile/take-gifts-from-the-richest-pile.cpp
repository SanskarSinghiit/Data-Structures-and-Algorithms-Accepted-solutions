class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> pq;
        for(auto val : gifts){
            pq.push(val);
        }
        while(k--){
            int x = pq.top();
            pq.pop();
            pq.push(floor(sqrt(x)));
            // cout << "this is x -> " << x << '\n';
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};