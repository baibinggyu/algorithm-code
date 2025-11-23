#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1) return "1";
            string temp =  countAndSay(n - 1);  
            string res;          
            string::iterator it = temp.begin();
            int count = 0;
            while(it != temp.end())
            {
                count++;
                if(*it != *(it + 1))
                {
                    res += to_string(count) + *it;
                    count = 0;
                }
                it++;
            }
            return res;
        }
    };
 