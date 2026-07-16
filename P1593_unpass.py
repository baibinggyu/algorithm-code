MOD = 9901
a, b = map(int, input().split())


def quick_pow(a: int, b: int) -> int:
    if a == 1:
        return 1
    if b == 0:
        return 1
    res = 1
    while b > 0:
        if b & 1 == 1:
            res *= a
        a *= a
        b = b >> 1
    return res


top = quick_pow(a, b)
hash = set()
curIndex = 2
while curIndex <= top:
    if a % curIndex == 0:
        hash.add(curIndex)
        a //= curIndex
        continue
    curIndex += 1

parr = []


def bfs(cur: int) -> None:
    parr.append(cur)
    if cur > top:
        return
    for value in hash:
        next = cur * value
        if next > top:
            continue
        bfs(next)


bfs(1)
res = 0
for idx, val in enumerate(parr):
    res = ((res % MOD) + (val % MOD)) % MOD
print(res)
