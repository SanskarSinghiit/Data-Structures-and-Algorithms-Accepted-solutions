#include<bits/stdc++.h>

class CustomStack {
public:

    vector<pair<int,int>> vec;
    int mx;
    int count = 0;

    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(vec.size()==mx){return;}
        vec.push_back({x, 0});
    }
    
    int pop() {
        if(vec.size()==0){return -1;}
        int x = vec.back().first;
        int y = vec.back().second;
        if(y==0 || vec.size()==1){
            int r = vec.back().first+vec.back().second;
            vec.pop_back();
            return r;
        } else{
            count = y;
            int z = vec.back().first;
            vec.pop_back();
            vec.back().second += count;
            return z+y;
        }
        return -2;
    }
    
    void increment(int k, int val) {
        if(vec.size()==0){return;}
        int minimum = vec.size() < k ? vec.size()-1 : k-1;
        vec[minimum].second += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */