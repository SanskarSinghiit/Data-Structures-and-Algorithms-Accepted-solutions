#define pi pair<int,int>

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<vector<int>> nums;  // time, arrival | departure, friend_id;
        for(int i = 0; i < n; i++){
            nums.push_back({times[i][0],1, i});
            nums.push_back({times[i][1],0,i}); // departure
        }
        priority_queue<int,vector<int>,greater<int>> pq; // minheap pq to track smallest empty chair at any given moment
        sort(nums.begin(), nums.end());
        int last_chair=0;
        map<int,int> mp; // to keep track of friend-chair;
        // nums[i] = {time, friendId}
        // return -1; // to debug TLE
        for(int i = 0; i < nums.size(); i++){
            int chair_taken = -1;
            if(nums[i][1]==1){
                int arrives_at = nums[i][0];
                int friend_id = nums[i][2];
                if(pq.size()==0){
                    mp.insert({friend_id, last_chair});//[last_chair]=friend_id;  
                    chair_taken = last_chair;
                    last_chair++; // keeps track of the last chair
                } else{
                    int x = pq.top(); pq.pop();
                    mp.insert({friend_id, x});//[x] = friend_id;
                    chair_taken = x;
                }
                if(targetFriend==friend_id){return chair_taken;}
            } else{
                int departs_at = nums[i][0];
                int friend_id = nums[i][2];
                // now how to find the chair that this friend has taken ??
                auto it = mp.find(friend_id);
                int current_chair = it->second;
                mp.erase(it);
                pq.push(current_chair);
            }
        } return -1; //
    }
};