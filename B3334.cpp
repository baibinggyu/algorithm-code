#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool isPrime(int n)
{
    if( n == 1 ) return false;
    for(int i = 2;i * i< (n + 1) ;i++)
        if ( n % i == 0) return false;
    return true;
}
signed main(void)
{
    int n;cin >> n;
    int temp,tempNum;
    int count = 0;
    for(int i = 1;i < n + 1;i++)
    {
        temp = 0; tempNum = i;
        while(tempNum)
        {
            temp += tempNum % 10;
            tempNum /= 10;
        }
        if(isPrime(temp)) ++count; 

    }
    cout << count << endl ;
    return 0;
}