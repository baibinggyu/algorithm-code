arr = list(map(int,input().split()))
dp = [0 for _ in range(len(arr))]
ans = 0
dp[0] = arr[0]
for i in range(1,len(dp)):
    if dp[ans] >= arr[i] :
        ans += 1
        dp[ans] = arr[i]
    else:
        l , r = 0 , ans 
        while l < r:
            mid = l + ((r - l) >> 1)
            if dp[mid] >= arr[i]:
                l = mid + 1
            else:
                r = mid
        dp[l] = arr[i]
system = []
for i in range(len(arr)):
    cur = arr[i]
    l , r = 0 , len(system) - 1
    while(l < r):
        mid = l + ((r - l) >> 1)
        if system[mid] >= cur:
            r = mid
        else:
            l = mid + 1
    flag = False
    if system and system[r] >= cur:
        system[r] = cur
        flag = True
    if not flag:
        system.append(cur)
ans += 1
print(ans,"\n",len(system),sep="")
        
    
