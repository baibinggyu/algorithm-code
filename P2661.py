n = int(input())
arr = list(map(int,input().split()))
arr.insert(0,0)
p = [i for i in range(n + 1)]
def find(x : int):
    if p[x] == x:
        return p[x]
    p[x] = find(p[x])
    return p[x]
def union_(a : int,b : int):
    x , y = find(a) , find(b)
    if x == y:
        return  
    if x > y:
        x , y = y , x
    p[x] = p[y]
ans = n
for i in range(1,n + 1):
    if find(i) == find(arr[i]):
        cnt , j = 1 , arr[i]
        while j != i:
            j = arr[j]
            cnt += 1
        ans = min(ans,cnt)
    else:
        union_(i,arr[i])
print(ans)