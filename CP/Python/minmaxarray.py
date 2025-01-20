n = int(input())
a = [int(i) for i in input().split()]

a.sort()

cnt1 = int(0)
cnt2 = int(0)

for i in range (0 , n) :
    if (a[i] == a[0]) : cnt1 += 1
    if (a[i] == a[n - 1]) : cnt2 += 1

print(a[0] ,  cnt1)
print(a[n - 1] , cnt2) 
