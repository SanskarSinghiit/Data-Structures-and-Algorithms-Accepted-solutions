class Solution {
public:

    void rec(int cv, int target, int copy, int oc, int& best){
        // cout << "cv-> " << cv << " copy-> " << copy << " oc-> " << oc << " best-> " << best << '\n';
        if(cv > target){return;}
        if(cv == target){if(oc < best){best=oc;} return;}
        rec(cv+copy, target, copy, oc+1, best);
        rec(cv+cv, target, cv, oc+2, best);
    }

    int minSteps(int n) {
        if(n==1){return 0;}
        int copy = 1;
        int cv = 1;
        int operationCount = 1;
        int best = INT_MAX;
        rec(1, n, copy, operationCount, best);
        return best;
    }
};