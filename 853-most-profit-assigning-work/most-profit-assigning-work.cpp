class Solution {
public:

    int findBestJob(vector<pair<pair<int, int>, int>>& job, int target){
        int n = job.size();
        int lo = 0;
        int hi = n-1;
        int mid = lo+(hi-lo)/2;
        int noteAns = 0;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(job[mid].first.first > target){
                hi = mid-1;
            } else{
                lo = mid+1;
                noteAns = max(noteAns, job[mid].second);
            }
        }
        return noteAns;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<pair<int, int>, int>> job;  // {{difficulty, profit}, cmp};
        int n = difficulty.size();
        int m = worker.size();
        for(int i = 0; i < n; i++){
            job.push_back({{difficulty[i], profit[i]}, 0});
        }
        int cmp = 0;
        sort(job.begin(), job.end());
        for(int i = 0; i < n; i++){
            int currJobProfit = job[i].first.second;
            if(currJobProfit > cmp){
                cmp = currJobProfit;
            }
            job[i].second = cmp;
        }
        // sort(worker.begin(), worker.end());
        int maxProfit = 0;
        // cout << "job size => " << job.size() << '\n';
        // cout << "printing job vector => " << '\n';
        // for(int i = 0; i < n; i++){
        //     cout << job[i].first.first << ' ' << job[i].first.second << ' ' << job[i].second << '\n';
        // }
        // vector<pair<int, int>> assign;
        for(int i = 0; i < m; i++){
            int bestProfit = findBestJob(job, worker[i]);
            // cout << "for worker => " << worker[i] << " bestProfit => " << bestProfit << '\n';
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};