n = int(input())
arr  = list(map(int,input().split()))
sum = [0 for _ in range(n)]
sum[0] = arr[0]
for i in range(1,n):
    sum[i] = sum[i - 1] + arr[i]
m = int(input())
for i in range(m):
    l,r = list(map(int,input().split()))
    if l == 1:
        print(sum[r - 1])
    else:
        print(sum[r - 1] - sum[l - 2])