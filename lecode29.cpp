#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend == 0) return 0;
            if(dividend == INT_MIN && divisor == -1) return INT_MAX;
            if(dividend == INT_MIN && divisor == 1) return INT_MIN;
            if(dividend == INT_MAX && divisor == -1) return INT_MIN + 1;
            if(dividend == INT_MAX && divisor == 1) return INT_MAX;
            int sign = 0;
            int count = 0;
            if(dividend > 0) {dividend = - dividend;sign++;}
            if(divisor > 0) {divisor = -divisor; sign++;}

            while(dividend  <=  divisor){
                count++;
                dividend -= divisor;
            }
            if(sign == 0 || sign == 2) return count;
            else return -count;
        }
    };