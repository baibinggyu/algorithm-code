MOD = 19260817 #质数
a = int(input().rstrip())
b = int(input().rstrip())
def exgcd(a,b):
    if b == 0:
        return a,1,0    
    g , x1 , y1 = exgcd(b,a % b)
    return g , y1 ,x1 - a // b * y1
g,x,y = exgcd(b,MOD)
if g != 1:
    print("Angry!")
else:
    print((x % MOD * a % MOD) % MOD)
    