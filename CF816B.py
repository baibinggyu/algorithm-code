n,k,q = list(map(int,input().split()))
arr = [[] for _ in range(n)]
for i in range(n):
    nums01,nums02 = list(map(int,input().split()))
    arr[i].append(nums01)
    arr[i].append(nums02)


for i in range(q):
    count = 0
    l,r = list(map(int,input().split()))
    diff = [n] * (r - l + 1)
    for val in arr:        
        if val[0] > r or val[1] < l:
            for j in range(len(diff)):
                diff[j] -= 1
            continue
        leftIndex = max(l,val[0]) - l 
        for j in range(leftIndex):
            diff[j] -= 1
        rightIndex = min(r,val[1]) - r
        for j in range(rightIndex,0):
            diff[j] -= 1
    for val in diff:
        if val >= k:
            count += 1
    print(count)