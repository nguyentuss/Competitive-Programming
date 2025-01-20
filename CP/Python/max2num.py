import math
n , q = map(int , input().split()) 

f = [0]*(n + 2)

for i in range(0 , q) :
    a , b , k = map(int , input().split())
    f[a] += k;
    f[b + 1] -= k
x = int(0)

ans = int(0)

for i in range (1 , n + 1) :
    x += f[i]   
    ans = max(ans , x)

print(ans)

