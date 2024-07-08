typedef long long ll;
class Solution {
public:

    bool lost[500] = {false};

    int findTheWinner(int n, int k) {
        // bool lost[n] = {false};
        ll curr = 0;
        for (ll i = 0; i < n - 1; i++) {
            while (lost[curr % n]) {
                curr = (curr + 1) % n;
            }
            // cout << "start with => " << curr << "  ";
            for (ll j = 0; j < k - 1; j++) {
                curr = (curr + 1) % n;
                while (lost[curr % n]) {
                    curr = (curr + 1) % n;
                }
                // cout << "(" << curr << "), " << "  ";
            }
            lost[curr % n] = true;
            // cout << "lost => " << curr << '\n';
            // cout << '\n';
            curr = (curr + 1) % n;
        }
        for (ll i = 0; i < n; i++) {
            if (lost[i] == false) {
                // cout << i + 1 << '\n';
                return i+1;
            }
        }

        return -1;
    }
};