class MyCalendarTwo {
public:

    map<int,int> mp;


    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        // cout << "for interval -> " << start << ' ' << end << "-------------" << '\n';
        int count = 0;
        for(auto val : mp){
            // cout << val.first << ' ' << val.second << '\n';
            //int count = 0;
            // cout << "this is before count -> " << count << '\n';
            // cout << "this is val.second -> " << val.second << '\n';
            count += val.second;

            // cout << "this is count -> " << count << '\n';
            if(count>=3){
                mp[start]--; mp[end]++;
                return false;
            }
            // count -= val.second;
        } 
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */