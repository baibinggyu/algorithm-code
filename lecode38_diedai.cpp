//迭代法解决
#include <iostream>
using namespace std;
class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1) return "1";
            string res = "1";
            string temp;
            --n;
            while(n--)
            {
                temp = res;
                res.clear();
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
                
            }
            return res;
        }
    };
