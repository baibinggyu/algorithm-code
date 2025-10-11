#include <bits/stdc++.h>
using namespace std;
bool cmp(const int a,const int b)
{return a > b;}
int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n,cmp);
    for(int i = 0;i < n;i++)
        printf("%d ",arr[i]);
    return 0;
}