#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int V_MAX = 100000000;
int n;
int arr[N][2],MAX[N],MIN[N];

bool check_min(int v)
{
    for(int i = 0;i < n;i++)
        if(arr[i][1] < arr[i][0] / v) return false;
    return true;
}
bool check_max(int v)
{
    for(int i = 0;i < n;i++)
        if(arr[i][1] > arr[i][0] / v) return false;
    return true;
}
int main(void)
{
    int min = INT_MAX,max = 0;
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < 2;j++) 
            cin >> arr[i][j];
    int l = 1,r = 100000000;
    // 检查小的
    while(l < r)
    {
        int mid = (l + r)>> 1;
        if(check_min(mid))
        {
            if(min > mid) min = mid;
            r = mid;
        }else l = mid + 1;                      
    }
    l = 1,r = 1e9;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check_max(mid))
        {
            if(max < mid) max = mid;
            l = mid;
        }else r = mid - 1;
    }
   cout << min << ' ' << max << endl;
    return 0;
}