from typing import List
n , m  = list(map(int,input().split()))
edges = []
for i in range(m):
    x , y ,z = list(map(int,input().split()))
    edges.append((z,x,y))

def find(x : int,p : List) -> int:
    if p[x] == x:
        return x
    p[x] = find(p[x],p)
    return p[x]
def union_(a : int ,b : int,p : List):
    x = find(a,p)
    y = find(b,p)
    if x == y:
        return False
    if x > y:
        x , y = y , x
    p[y] = p[x]
    return True
def quickSort(arr : List[List],left : int,right : int):
    if left >= right:
        return
    l , r = left,right
    p = arr[l + ((r - l) >> 1)][0]
    while l <= r:
        while arr[l][0] < p:
            l += 1
        while p < arr[r][0]:
            r -= 1
        if(l <= r): 
            arr[l] , arr[r] = arr[r] , arr[l]
            l += 1
            r -= 1
    quickSort(arr,left,r)
    quickSort(arr,l,right)
quickSort(edges,0,len(edges) - 1)
parent = [i for i in range(n + 1)]
res = 0
count = 0
for w , u , v in edges:
    if union_(u,v,parent):
        res += w
        count += 1  
        if count == n - 1:
            break
if count == n - 1:
    print(res)
else:
    print("orz")
