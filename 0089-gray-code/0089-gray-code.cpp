class Solution {
public: 
    vector<int> grayCode(int n)
    {
        int N = pow(2,16);
        vector<int> vec(N);
        vec[0] = 0;
        vec[1] = 1;
        // cout << N << "\n";
        // int arr[N];
        vector<int> arr(pow(2,n),-1);
        arr[0] = 0;
        arr[1] = 1; 
        int fornext = 0;
        int power = 0;
        // cout << "hi";
        for(int i = 2; i < pow(2,n); i++)
        {
            if(fornext!=0)
            {

                arr[i] = power + arr[2*power - i - 1];
                fornext--;
                continue;
            }
            if((i&(i-1))==0)
            {
                cout << "hi : " << i << '\n';
                fornext=i; power=i;
                cout << fornext << " " << power << '\n';
                arr[i] = power + arr[2*power - i - 1];
                fornext--;
            }
        }
        return arr;
    }
};