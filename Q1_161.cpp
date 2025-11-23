#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return abs(nums[0]);
        vector<int> front,back;
        vector<bool> isPrime(n + 1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2;i * i <= n;i++){
             for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
        }
        long long iFront = 0,iBack = 0;
        for(int i = 0;i < n;i++){
            if(isPrime[i]) iFront += nums[i];
            else iBack += nums[i];
        }
        return abs(iFront - iBack);
    }
};
signed main(void){
    Solution test;
    vector<int> arr({-462260177,-142373969,-305864676,-357426459});
    cout << test.splitArray(arr) << endl;
    return 0;
}