# Wythoff Game 数学公式
from math import sqrt
a , b = list(map(int,input().split()))
if a > b:
    temp = a 
    a = b
    b = temp
k = b - a
phi = round((1 + sqrt(5)) / 2,10)
if int(phi * k) == a:
    print(0)
else:
    print(1) 