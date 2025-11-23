#include <bits/stdc++.h>
using namespace std;
static int arr[100][100];
static int vis[100][100];
int startX,startY,endX,endY;
int ax[] = {-1,0,1,0};
int ay[] = {0,1,0,-1};
int n;
bool isPass = 0;
bool dfs(int x, int y)
{   
    vis[x][y] = 1;
    if(x == endX && y == endY) return true;
    for(int i = 0;i < 4;i++)
    {
        int nx = x + ax[i];
        int ny = y + ay[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == false && vis[nx][ny] == false && isPass == 0)
             if(dfs(nx,ny)) return true;
    }
    return false;
}

int main(void)
{
    
    cin >> n;
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> arr[i][j];
    cin >> startX >> startY >> endX >> endY;
    startX -= 1,startY -= 1,endX -= 1,endY -= 1;
    if(arr[startX][startY] || arr[endX][endY]) 
    {
        cout << "NO" << endl;
        return 0;
    }
    isPass = dfs(startX,startY);
    puts(isPass ? "YES" : "NO" );
    return 0;
}