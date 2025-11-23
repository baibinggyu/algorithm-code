#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(void)
{
    int n;
    cin >> n;
    int num01,num02;
    for(int i = 0;i < n;i++)
    {
        cin >> num01 >> num02;
        cout << __gcd(num01,num02) << endl;
    }

    return 0;
}