n = int(input())
arr = list(map(int,input().split()))
q = int(input())
dic = {}
for i,val in enumerate(arr):
    dic[val] = i + 1
for i in range(q):
    need = int(input())
    if need in dic:
        print(dic[need])
    else:
        print(0)