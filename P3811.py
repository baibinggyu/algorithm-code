import sys
input = sys.stdin.readline
def exgcd(a : int,b : int):
    if b == 0:
        return a , 1, 0
    g , x ,y = exgcd(b , a % b)
    return g,y , x - a // b * y
n , p = map(int,input().split())
ans = []
for i in range(1,n + 1):
    g , x ,y = exgcd(i,p)
    ans.append(x % p)
for val in ans:
    print(val)