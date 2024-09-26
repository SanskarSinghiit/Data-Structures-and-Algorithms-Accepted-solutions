class MyCalendar {

private:
    // set<int> st;

    vector<pair<int,int>> vec;
public:


    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(vec.size()==0){vec.push_back({start,end}); return true;}
        for(auto val : vec){
            int a = val.first;
            int b = val.second;
            if(a<end && b>start){return false;}
        }
        vec.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */