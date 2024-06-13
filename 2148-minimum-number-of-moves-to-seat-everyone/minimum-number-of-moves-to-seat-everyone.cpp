class Solution {
public:

    // void print(queue<int>& qu){
    //     queue<int> q = qu;
    //     while(!q.empty()){
    //         cout << q.front() << ' ';
    //         q.pop();
    //     } cout << '\n';
    // }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = max(*max_element(seats.begin(), seats.end()), *max_element(students.begin(), students.end()));
        // set<int> stseat, ststudent;
        int m = seats.size();
        map<int, int> mpseat, mpstudent;
        for(int i = 0; i < m; i++){
            mpseat[seats[i]]++;
            mpstudent[students[i]]++;
        }
        // cout << "printing maps : => " << '\n';
        // cout << "mpseat => " << '\n';
        // for(auto val : mpseat){
        //     cout << val.first << ' ' << val.second << '\n';
        // } 
        // // cout << "mpstudent => " << '\n';
        // for(auto val : mpstudent){
        //     cout << val.first << ' ' << val.second << '\n';
        // } 
        queue<int> qseat;
        queue<int> qstudent;
        vector<pair<int, int>> paired; // pair<seat, student>;
        for(int i = 1; i <= n; i++){
            // cout << "for i = " << i << '\n';
            if(mpseat[i] != 0){
                // cout << i << " found in mpseat" << "  ";
                // mpseat[i]--;
                int z = mpseat[i];
                // cout << " z seat => " << z << "           ";
                while(z--){
                    qseat.push(i);
                }
            }
            if(mpstudent[i] != 0){
                // mpstudent[i]--;
                // cout << i << " found in mpstudent" << "  ";
                int z = mpstudent[i];
                // cout << " z student => " << z << "        ";
                while(z--){
                    qstudent.push(i);
                }
            }
            // cout << "for i = " << i << " queues are => " << '\n';
            // cout << "qseat => ";
            // print(qseat);
            // cout << "qstudent => ";
            // print(qstudent);
            //  cout << '\n';
        }
        while(!qseat.empty() && !qstudent.empty()){
            int x = qseat.front();
            int y = qstudent.front();
            paired.push_back({x, y});
            qseat.pop();
            qstudent.pop();
        }
        int calculate = 0;
        for(auto val : paired){
            calculate += abs(val.first - val.second);
        }
        return calculate;
    }
};