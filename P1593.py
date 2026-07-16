MOD = 9901
a, b = map(int, input().split())
if a == 1 or b == 0:
    print(1)
    exit(0)
hash = set()
curIndex = 2
cnt = {}
while curIndex <= a:
    if a % curIndex == 0:
        if curIndex in cnt:
            cnt[curIndex] += 1
        else :
         cnt[curIndex] = 1
        hash.add(curIndex)
        a = a // curIndex
        continue
    curIndex += 1
def quick_pow(a: int, p: int) -> int:
    if a == 1:
        return 1
    if p == 0:
        return 1
    res = 1
    while p > 0:
        if p & 1 == 1:
            res *= a
        a *= a
        p = p >> 1
    return res
n = len(hash)
def calc_sum(q: int, n: int) -> int:
    return (1 - quick_pow(q, n)) // (1 - q)
res = 1 
for val in hash :
    res = ((res % MOD) * (calc_sum(val,cnt[val] * b + 1) % MOD) ) % MOD
print(res)

