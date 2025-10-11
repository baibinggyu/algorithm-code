n = int(input())
arr = a = list(map(int, input().split()))
sum = 0 
bit = 21
bits = 1
for i in range(bit):
    count0 = 0 
    count1 = 0
    sum0 = 0
    sum1 = 0
    for j in range(n):
        if  (arr[j] >> i) & 1:
            count1  += 1
            sum1 +=  j + 1
            sum += bits * (count0 *(j + 1) - sum0)
        else :
            count0 += 1
            sum0 += j + 1
            sum += bits * (count1 * (j + 1) - sum1)
    bits <<= 1


print(sum)