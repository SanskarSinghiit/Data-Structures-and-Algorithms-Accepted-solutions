class Solution {
public:
    int countPrimes(int n) {
        // bool isPrime[n+1] = {true};
    //     vector<bool> isPrime(n+1, true);
    //     isPrime[0] = isPrime[1] = false;
    //     for(int i = 2; i <= sqrt(n); i++){
    //         if(isPrime[i]){
    //             for(int j = i*i; j <= n; j+=i){
    //                 isPrime[j] = false;
    //             }
    //         }
    //     }
    //     int count = 0;
    //     for(int i = 0; i < n; i++){
    //         if(isPrime[i]){count++;}
    //     }
    //     return count;
    // }
    // bool isPrime[n+1] = {true};
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isPrime[i]){count++;}
    }
    return count;
    }
};