n = int(input())

a = [int(i) for i in input().split()]

s = int(0)
cnt = int(0)

for i in range (0 , n):
    if (a[i] > a[n - 1]) :
        s += a[i]
        cnt+=1

print(cnt)
print(s) 
