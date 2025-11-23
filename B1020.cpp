#include <bits/stdc++.h>
using namespace std;
#define int long long
static int arr[105];
int cnt = 1;
static int prime[105];
bool isPrime(int n)
{
    if(prime[n]) return true;
    if(n == 1) return false;
    for(int i = 2;i * i < n + 1;++i) if(!(n % i)) return false;
    prime[n] = 1;
    return true;
}
signed main(void)
{
    for(int i =  2;i < 101;i++)
    {
        int temp = i;
        for(int j =  2;j < i + 1;j++)
            if(!(temp % j)) 
            {
                ++arr[j]; 
                temp /= j;
                --j;
            }
    }
    for(int i = 0;i < 105;i++) cnt *= arr[i] + 1;
    cout << cnt << endl;
    return 0;
}
