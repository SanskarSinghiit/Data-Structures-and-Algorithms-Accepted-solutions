class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int finishAt = 0;
        vector<int> waitingTime(n, -1);
        for (int i = 0; i < n; i++) {
            int arrival = customers[i][0];
            int timeNeeded = customers[i][1];
            if (finishAt > arrival) {
                waitingTime[i] = finishAt - arrival + timeNeeded;
                finishAt += timeNeeded;
            } else{
                waitingTime[i] = timeNeeded;
                finishAt = arrival + timeNeeded;
            }
        }
        double x = 0;
        for(int i = 0; i < n; i++){
            x += waitingTime[i];
        }
        x = x/(n*1.0);
        return x;
    }
};