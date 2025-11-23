#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int myAtoi(string s) {
            if(s.size() ==0) return 0;
            long res = 0;
            int sign = 1;
            int index = 0;
            while(index < s.size() && s[index] == ' ') index++;
            if(index >= s.size()) return 0;
           if(s[index] == '-' || s[index] == '+') 
            {
                if(s[index] == '-') sign = -1;
                index++;
            }
           if(index < s.size() && !isdigit(s[index])) return 0;
            while(index < s.size() && isdigit(s[index]))
            {
                int digit = s[index] - '0';
                if(res > INT_MAX / 10 || (res ==INT_MAX / 10 && digit > (sign == 1? 7:8)))
                    return sign == 1 ? INT_MAX : INT_MIN;
                res = res*10 + digit;
                index++;
            }
            return sign * res;
        }
    };