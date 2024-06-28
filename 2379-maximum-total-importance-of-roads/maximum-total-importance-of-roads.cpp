class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<long long, long long> mp;   // node, no.of childrens
        long long m = roads.size();
        for(long long i = 0; i < m; i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        // cout << "printing map => " << '\n';
        // for(auto val : mp){
        //     cout << val.second << ' ' << val.first << '\n';
        // }
        vector<pair<long long, long long>> vec;  // no. of childrens, node
        for(auto val : mp){
            vec.push_back({val.second, val.first});
        }
        sort(vec.begin(), vec.end());
        long long pr = n;
        long long sum = 0;
        // cout << "vecsize =>" << vec.size() << '\n';
        // cout << "printing vector => " << '\n';
        // auto q = vec[0];
        // cout << q.first << ' ' << q.second << ' ' << '\n';
        n = vec.size();
        for(int i = 0; i < n/2; i++){swap(vec[i], vec[n-i-1]);}
        // cout << '\n';
        // for(int i = 0; i < n; i++){
        //     auto q = vec[i];
        //     // cout << q.first << ' ' << q.second << '\n';
        // }
        for(long long i = 0; i < n; i++){
            sum += (pr*(vec[i].first));
            // cout << "pr => " << pr << " vec[i].first => " << vec[i].first <<  " vec[i].second => " << vec[i].second << " sum => " << sum << '\n';
            pr--;
        }
        return sum;
    }
};