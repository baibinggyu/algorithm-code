count = 0
data = input()
n,c = map(int,data.split())
data = input()
arr = list(map(int,data.split()))
dic = {}
for val in arr:
    if val in dic:
        dic[val] += 1
    else:
        dic[val] = 1
for val in arr:
    if val + c in dic:
        count += dic[val + c]
print(count)