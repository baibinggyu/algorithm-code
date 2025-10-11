#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            unordered_map<int,string> hashTable;
            hashTable[1] = "I";
            hashTable[4] = "IV";
            hashTable[5] = "V";
            hashTable[9] = "IX";
            hashTable[10] = "X";
            hashTable[40] = "XL";
            hashTable[50] = "L";
            hashTable[90] = "XC";
            hashTable[100] = "C";
            hashTable[400] = "CD";
            hashTable[500] = "D";
            hashTable[900] = "CM";
            hashTable[1000] = "M";
            string res;
            int bit = 10000;
            while(bit != 1)
            {
                int a = num % bit / (bit / 10);
                bit /= 10;
                if(a == 4 || a == 5 || a == 9 || a== 10) res += hashTable[a * bit];
                else if (a < 4) for(int i =  0;i < a;i++) res += hashTable[bit];
                else {
                    res += hashTable[5*bit];
                    for(int i = 5;i < a;i++) res += hashTable[bit];
                }
            }
            return res;
        }
    };