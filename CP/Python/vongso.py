import math
n , k = map(int , input().split())
a = [int(i) for i in input().split()]
f = [0]*(n + 1)

for i in range(1 , n + 1):
    f[i] = f[i - 1] + a[i - 1]

ans = int(-10000000000000)
for i in range(1 , n + 1):
    r = i + k - 1
    ans = max(ans , f[min(n , r)] - f[i - 1] + f[max(0 , r - n)])

print(ans)
