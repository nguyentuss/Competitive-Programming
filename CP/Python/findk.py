n = int(input())
a = [int(i) for i in input().split()]
k = int(input())
cnt = int(0)
for i in range (0 , n):
    if (a[i] == k) :
        print(i + 1 ,end = ' ')
        cnt+=1
if (cnt == 0) :
    print(-1)
