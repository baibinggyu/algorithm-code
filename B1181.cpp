//2025年3月12日，掌握不太好，快速幂，同模运算
#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(void)
{
    int count,n,m,p,res;
    cin >> count;
    for(int i = 0;i < count;i++)
    {
        res = 1;
        cin >> n >> m >> p;
        while(m)
        {
            if((m & 1) == 1) res = res * n  % p;
            n = n * n % p;
            m >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}