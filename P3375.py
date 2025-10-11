s1 = input().strip()
s2 = input().strip()
nxt = [0] * len(s2)
jj = 0
for i in range(1,len(s2)):
    while jj > 0 and s2[i] != s2[jj]:
        jj = nxt[jj - 1]
    if s2[i] == s2[jj] :
        jj += 1
    nxt[i] = jj    
res = []
j = 0
for i in range(len(s1)):
    while j > 0 and s1[i] != s2[j]:
        j = nxt[j - 1]
    if s1[i] == s2[j]:
        j += 1
    if j == len(s2):
        res.append(i - j + 2)
        j = nxt[j - 1]
for val in res:
    print(val)
print(" ".join(map(str,nxt)))