n , k = map(int , input().split())
a = [int(i) for i in input().split()]
for i in range(k , n):
    print(a[i],end=' ')
for i in range(0 , k):
    print(a[i],end=' ')
