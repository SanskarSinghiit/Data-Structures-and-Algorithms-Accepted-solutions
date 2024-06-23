class Solution {
public:

    void dequeToVec(deque<int>& dq, vector<int>& temp){
        temp = {};
        for(auto val : dq){
            temp.push_back(val);
        }
    }

    void print(deque<int>& dq){
        for(auto val : dq){
            cout << val << ' ';
        } cout << '\n';
    }

    void print(multiset<int>& ms){
        for(auto val : ms){
            cout << val << ' ';
        } // cout << '\n';
    }

    vector<vector<int>> generate(vector<int>& nums, int sz){
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        deque<int> dq;
        while(j-i+1 <= sz){
            // temp.push_back(nums[j]);
            dq.push_back(nums[j]);
            j++;
        }
        // cout << "deque outside first while =>  ";
        // print(dq);
        dequeToVec(dq, temp);
        ans.push_back(temp);
        while(j < n){
            // cout << "hi ";
            dq.pop_front();
            dq.push_back(nums[j++]);
            // cout << "deques inside while2 =>  ";
            // print(dq); 
            // cout << j << '\n';
            dequeToVec(dq, temp);
            ans.push_back(temp);
        }
        //cout << '\n' << '\n';
        return ans;
    }

    bool validAns(int sz, vector<int>& nums, int limit){
        // generate all possible subarrays of size val, and find from that;
        // vector<vector<int>> sub = generate(nums, val);
        // cout << "printing all subs of size = " << val << '\n';
        /* for(auto v : sub){
            for(auto val : v){
                cout << val << ' ';
            } cout << '\n';
        } */
        // priority_queue<int> maxpq;
        // priority_queue<int, vector<int>, greater<int>> minpq;
        int i = 0;
        int j = 0;
        int M = -1;
        int m = -1;
        int n = nums.size();
        // vector<int> temp;
        // deque<int> dq;
        multiset<int> ms;
        while(j-i+1 <= sz){
            // maxpq.push(nums[j]);
            // minpq.push(nums[j]);
            // dq.push_back(nums[j]);
            ms.insert(nums[j]);
            j++;
        }
        M = *(--ms.end());
        m = *(ms.begin());
        // print(ms);
        // cout << "  M-> " << M << "  m-> " << m << '\n';
        // M = maxpq.top();
        // m = minpq.top();
        // dequeToVec(dq, temp);
        // sort(temp.begin(), temp.end());
        // if(*max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end()) <= limit){
        //     return true;
        // }
        if(M - m <= limit){
            return true;
        }
        // if(M-m <= limit){
        //    return true;
        // }
        while(j < n){
            // dq.pop_front();
            // dq.push_back(nums[j++]);
            // dequeToVec(dq, temp);
            // sort(temp.begin(), temp.end());
            // if(*max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end()) <= limit){
            //     return true;
            // }
            int eras = nums[i++];
            ms.erase(ms.find(eras));
            ms.insert(nums[j++]);
            M = *(--ms.end());
            m = *(ms.begin());
            // print(ms);
            // cout << "  M->" << M << "  m->" << m << '\n';
            if(M-m <= limit){
                return true;
            }
        }
        return false;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        // cout << validAns(4, nums, limit) << '\n';
        int n = nums.size();
        int lo = 1;
        int hi = n;
        int mid = lo + (hi-lo)/2;
        int maxi = -1;
        while( lo <= hi){
            mid = lo + (hi-lo)/2;
            if(validAns(mid, nums, limit)){
                maxi = (maxi < mid) ? mid : maxi;
                // cout << "mid = " << mid << " is a valid answer  ";
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        return maxi;
    }
};