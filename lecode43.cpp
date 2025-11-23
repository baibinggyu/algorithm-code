#include <string>
#include <vector>
using namespace std;
class Solution {
    public:
        string multiply(string num1, string num2) {
            int n = num1.size(),m = num2.size();
            vector<int> table(m + n ,0);
            for(int i = n - 1;i >= 0;i--)
                for(int j = m - 1;j >= 0;j--)
                {
                    int num = (num1[i] - '0') * (num2[j] - '0');
                    int p1 = i + j + 1,p2 = i + j;
                    table[p1] = table[p1] +  num;
                    if(table[p1] > 9) {table[p2] += table[p1] / 10;table[p1] = table[p1] % 10;}
                    if(table[p2] > 9) {table[p2 - 1] += table[p2] / 10;table[p2] = table[p2] % 10;}                     
                }
            string res;
            int index = 0;
            for(int temp : table)
            {
                if(temp == 0) index++;
                else break;
            }
            for(int i = index;i < table.size();i++)
                    res += to_string(table[i]);
            return res != "" ? res : "0";
        }
    };