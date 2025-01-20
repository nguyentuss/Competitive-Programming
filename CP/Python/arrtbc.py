n = int(input())

a = [int(i) for i in input().split()]

average = int(0)
s = int(0)

for i in range (0 , n):
    average += a[i]
average = average/n

for i in range (0 , n):
    if (a[i] > average):
        s += a[i]
if (s == 0) :
    print(-1)
else :
    print(s)
 
