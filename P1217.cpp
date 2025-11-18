    #include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define int long long
static bool flag[100000005];
int a,b;
bool isReturn(int& n)
{
    int temp = 0, num = n;
    while(num)
    {
        temp = temp * 10 + num % 10;
        num /= 10;
    }
    if(n == temp) return true;
    else return false;
}
bool isPrime(int n)
{
    if(n == 0 || n == 1) return false;
   for(int i = 2;i * i < n + 1 ;i++) if( n % i == 0) return false;
   return true;
}   

void primeTable(void)
{
    memset(flag,true,sizeof(int) * (b+1));
    for(int i = 2;i < b + 1;i++)
    {
        if(flag[i] && isPrime(i) )
        {
            for(int j = 2;j * i < b + 1 ;j++)
                flag[j * i] = 0;
        }
    }
}
signed main(void)
{
    
    cin >> a >> b;
    primeTable();
    for(int i = a;i < b + 1;i++)
        if(flag[i] && isReturn(i))
            cout << i << endl;
    

    return 0;
}