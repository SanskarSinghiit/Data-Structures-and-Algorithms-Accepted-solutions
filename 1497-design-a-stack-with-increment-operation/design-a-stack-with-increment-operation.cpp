class CustomStack {

public:

    vector<int> vec;
    int mx, sz=0;
    // int i = 0;

    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(sz==mx){return;}
        sz++;
        vec.push_back(x);
    }
    
    int pop() {
        if(sz==0){return -1;}
        sz--;
        int x = vec.back();
        vec.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, sz); i++){
            vec[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */