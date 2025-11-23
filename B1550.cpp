#include <iostream>
using namespace std;
static int res[100][100];
signed main(void)
{
	int n,m,k;
	cin >> n >> m >> k;
	int** arr = (int**)malloc(sizeof(int*) * n);
	for(int i = 0;i < n;i++) arr[i] = (int*)malloc(sizeof(int) * m);
	int** arr02 = (int**)malloc(sizeof(int*) * m);
	for(int i = 0;i < m;i++) arr02[i] = (int*)malloc(sizeof(int) * k);
	for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> arr[i][j];
	for(int i = 0;i < m;i++) for(int j = 0;j < k;j++) cin >> arr02[i][j];
	for(int i = 0;i < n;i++) 
	{
	for(int j = 0;j < k;j++)
	{
	for(int a = 0;a < m;a++) res[i][j] += arr[i][a] * arr02[a][j];

	cout << res[i][j] << ' ';
	}
	cout << endl;}
	return 0;
}
