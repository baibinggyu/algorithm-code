#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int expand(int left,int right,string str)
        {
            while(left > -1 && right < str.size() && str[left] == str[right])
            {
                left--;
                right++;
            }
            return right - left  - 1;
        }
        int max(int num01,int num02){return num01 > num02 ? num01 : num02;}
        string longestPalindrome(string s) {
            if(s.size() < 1 || s == "") return "";
            int maxLen = 1,tempMax = 1,tempLen01 =1,tempLen02 = 1,start = 0;
            for(int i = 0 ;i < s.size();i++)
            {   
                tempLen01 = expand(i,i,s);
                tempLen02 = expand(i,i+1,s);
                tempMax = max(tempLen01,tempLen02);
                if(tempMax > maxLen)
                {
                    maxLen = tempMax;
                    start = i - (tempMax -1 ) / 2;
                }
            }
            return s.substr(start,maxLen);
        }
    };