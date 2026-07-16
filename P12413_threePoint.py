def calc(arr: list, n: int, w: int) -> int:
    res = n * w
    for value in arr:
        res += 0 if value - n < 0 else value - n
        n += 1
    return res


n, w = list(map(int, input().split()))
arr = list(map(int, input().split()))

arr.sort(reverse=False)

l, r = 0, int(2e9)
while r - l > 3:
    m1 = int(l + (r - l) / 3)
    m2 = int(r - (r - l) / 3)
    if calc(arr, m1, w) < calc(arr, m2, w):
        r = m2
    else:
        l = m1
ans = 0x3f3f3f3f3f
for idx in range(l, r + 1):
    ans = min(ans, calc(arr, idx, w))
print(ans)
