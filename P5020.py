import sys
import collections
input = sys.stdin.readline
loop = int(input())
def MoneySystem()->int:
    n = int(input())
    arr = list(map(int,input().split()))
    arr.sort()
    m = arr[-1]
    data = [0] * (m + 1)
    data[0] = 1
    cur = 0
    for val in arr:
        if data[val]:
            data[val] = 0x3f3f3f3f
            continue
        flag = False
        cur = 0
        while cur + val <= arr[-1]:
            idx = cur + val
            if data[cur]:
                data[idx] += 1
            cur += 1
    res = 0
    for val in arr:
        if data[val] == 1:  
            res += 1
    return res
while loop:
    loop -= 1
    sys.stdout.write(str(MoneySystem()) + '\n')
