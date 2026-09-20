#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        string res;
        bool carry = 0;    
        while (~n && ~m){
            if(carry){
                if(a[n] == '1' && b[m] == '1') res += '1';    
                else if (a[n] == '1' ||b[m] == '1') res += '0';
                else {res += '1';carry = false;}
            }else {
                if(a[n] == '1' && b[m] == '1') {res += '0';carry = true;}
                else if(a[n] == '1' || b[m] == '1') res += '1';
                else res += '0';
            }
            n--,m--;
        }
        if(~n){
            while(~n){
                if(carry){
                    if(a[n] == '1') res += '0';
                    else if (a[n] == '0') {
                        carry = false;
                        res += '1';
                    }
                }else {
                    for(int i = n;~i;i--)
                        res += a[i];
                    reverse(res.begin(),res.end());
                    return res;
                }
                n--;
            }
        }        
        if(~m){
            while(~m){
                if(carry){
                    if(b[m] == '1') res += '0';
                    else if (b[m] == '0') {
                        carry = false;
                        res += '1';
                    }
                }else {
                    for(int i = m;~i;i--)
                        res += b[i];
                    reverse(res.begin(),res.end());
                    return res;
                }
                m--;
            }
            
        }
        if(carry) res += '1';
        reverse(res.begin(),res.end());
        for(int i = 0;i < res.size();i++){
            if(res[i] != '0') return res.substr(i);    
        }   
        return res;

    }
};