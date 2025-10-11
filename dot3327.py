import sys
input = sys.stdin.readline
n , k = list(map(int,input().split()))
arr = list(map(int,input().split()))
change = 1
while True:
    flag = True
    for i in range(n):
        if i + k < n and arr[i] > arr[i + k]:
            flag = False
            arr[i] -= 1
            arr[i + k] += 1
    if flag:
        break
ans = 0x3f3f3f3f
for val in arr:
    ans = min(val,ans)
print(ans)