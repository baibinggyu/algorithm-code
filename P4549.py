n = int(input())
arr = list(map(int,input().split()))
def gcd(a : int ,b : int)->int:
    if b == 0:
        return a
    return gcd(b , a % b)
if n == 1:
    print(abs(arr[0]))
else:
    g = gcd(arr[0],arr[1])
    for i in range(2,len(arr)):
        g = gcd(g,gcd(arr[i],arr[i - 1]))
    print(abs(g))