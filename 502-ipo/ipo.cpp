#include <bits/stdc++.h>

class Solution {
public:

    void pushAll(priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>& minpq, vector<int>& profits, vector<int>& capital){
        long long n = profits.size();
        for(long long i = 0; i < n; i++){
            pair<long long, long long> x = make_pair(capital[i], profits[i]);
            minpq.push(x);
        }
        return;
    }
    // void consume(pair<long long, long long> y, long long& w){
    //     w += y.second();
    //     return;
    // }


    long long findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> minpq;
        priority_queue<pair<long long, long long>> maxpq;
        long long n = profits.size();
        pushAll(minpq, profits, capital);
        while(!minpq.empty()){
            auto x = minpq.top();
            if(x.first <= w){
                maxpq.push({x.second, x.first});
                minpq.pop();
            } else{
                break;
            }
        }

        while(!maxpq.empty() && k>0){
            auto y = maxpq.top();
            maxpq.pop();
            w+=y.first;
            // consume(y, w);  // w -> w'
            k--;
            // since w -> w' so new greater capital we have, so new projects can be added which can't be added before
            while(!minpq.empty()){
                auto x = minpq.top();
                if(x.first <= w){
                    maxpq.push({x.second, x.first});
                    minpq.pop();
                } else{break;}
            }
        }
        return (int)w;
    }
};