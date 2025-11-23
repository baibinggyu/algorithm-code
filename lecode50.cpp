#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        double myPow(double x, int N) {
            long long n = N;
            if(n < 0) 
            {
                n = -n;
                x = 1 / x;
            }
            double res = 1;
            while(n)
            {
                if(n & 1)
                    res *= x;
                x *= x;
                n >>= 1;
            }
            return res;
            
        }
    };