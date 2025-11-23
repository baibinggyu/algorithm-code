n , k = list(map(int,input().split()))
k = k ^ (k >> 1)
print(bin(k)[2:].zfill(n))